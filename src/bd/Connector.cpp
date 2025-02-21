#include <iostream>
#include <sqlcipher/sqlite3.h>

#include "Connector.h"

#include <fstream>
#include <sstream>

namespace bd {
    // Protected
    Connector *Connector::m_connector = nullptr;

    Connector::Connector(const std::string& dbFilePath, const std::string& key) {
        if (dbFilePath.empty()) {
            std::cerr << "Database path is empty\n";
            return;
        }

        // Ouvrir la base de données
        int res = sqlite3_open(dbFilePath.c_str(), &m_bd);
        if (res != SQLITE_OK) {
            std::cerr << "Erreur lors de l'ouverture de la base de données : "
                      << sqlite3_errmsg(m_bd) << std::endl;
            if (m_bd) sqlite3_close(m_bd);
            m_bd = nullptr;
            return;
        }

        // Définir la clé pour SQLCipher
        std::string pragma_key = "PRAGMA key = '" + key + "';";
        char* err_msg = nullptr;
        res = sqlite3_exec(m_bd, pragma_key.c_str(), nullptr, nullptr, &err_msg);
        if (res != SQLITE_OK) {
            std::cerr << "Erreur lors de l'application de la clé : " << err_msg << std::endl;
            sqlite3_free(err_msg);
            sqlite3_close(m_bd);
            m_bd = nullptr;
            return;
        }

    	std::ifstream schemaFile("data/creation.sql");
    	if (schemaFile) {
    		std::ostringstream buffer;
    		buffer << schemaFile.rdbuf();
    		std::string sql = buffer.str();

    		res = sqlite3_exec(m_bd, sql.c_str(), nullptr, nullptr, &err_msg);
    		if (res != SQLITE_OK) {
    			std::cerr << "Erreur lors de l'exécution du fichier SQL : " << err_msg << std::endl;
    			sqlite3_free(err_msg);
    		}
    	} else {
    		std::cerr << "Impossible de charger le fichier schema.sql" << std::endl;
    	}
    }

    // Public
    Connector::~Connector() {
        if (m_bd) {
            sqlite3_close(m_bd);
            m_bd = nullptr;
        }
        if (m_connector) {
            delete m_connector;
            m_connector = nullptr;
        }
    }

    sqlite3 *Connector::getDB() const {
        return m_bd;
    }

    Connector &Connector::getInstance() {
        if (m_connector == nullptr)
            m_connector = new Connector("data/passwords.sqlite", std::getenv("DB_KEY"));
        return *m_connector;
    }
} // bd