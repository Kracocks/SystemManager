//
// Created by kracocks on 24/01/25.
//

#include "IdentifiantDaoImpl.h"
#include "../model/Service.h"
#include <iostream>
#include <ostream>

namespace impl {
    IdentifiantDaoImpl::IdentifiantDaoImpl(): m_connector(bd::Connector::getInstance()) {}

    std::vector<model::Identifiant<>> IdentifiantDaoImpl::findAll() {
        std::vector<model::Identifiant<>> identifiants;
    	std::vector<model::Service> services;
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT login_id, email, password "
								"FROM LOGIN;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v3(bd, sql.c_str(), -1, SQLITE_PREPARE_PERSISTENT, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all LOGIN : \n" << sqlite3_errmsg(bd) << std::endl;
        	if (stmt) sqlite3_finalize(stmt);
            return identifiants;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            model::Identifiant<> identifiant = model::Identifiant<>(
            	sqlite3_column_int(stmt, 0),
            	reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
            	reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)),
            	false);
        	identifiants.push_back(identifiant);
        }

        sqlite3_finalize(stmt);
        return identifiants;
    }

    std::vector<model::Identifiant<>> IdentifiantDaoImpl::findByEmail(std::string &&email) {
        std::vector<model::Identifiant<>> identifiants;
        sqlite3 *bd = m_connector.getDB();
    	const std::string sql = "SELECT login_id, email, password "
								"FROM LOGIN "
								"where email LIKE ?;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all LOGIN by email : \n" << sqlite3_errmsg(bd) << std::endl;
        	if (stmt) sqlite3_finalize(stmt);
            return identifiants;
        }
    	sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_TRANSIENT);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            model::Identifiant<> identifiant = model::Identifiant<>(
				sqlite3_column_int(stmt, 0),
            	reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
            	reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)),
            	false);
        	identifiants.push_back(identifiant);
        }

        sqlite3_finalize(stmt);
        return identifiants;
    }

    std::vector<model::Identifiant<>> IdentifiantDaoImpl::findByEmail(const std::string &email) {
        std::vector<model::Identifiant<>> identifiants;
        sqlite3 *bd = m_connector.getDB();
    	const std::string sql = "SELECT login_id, email, password "
								"FROM LOGIN "
								"where email LIKE ?;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all LOGIN by email : \n" << sqlite3_errmsg(bd) << std::endl;
        	if (stmt) sqlite3_finalize(stmt);
            return identifiants;
        }
    	sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_TRANSIENT);

    	while (sqlite3_step(stmt) == SQLITE_ROW) {
    		model::Identifiant<> identifiant = model::Identifiant<>(
				sqlite3_column_int(stmt, 0),
				reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)),
				reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)),
				false);
    		identifiants.push_back(identifiant);
    	}

        sqlite3_finalize(stmt);
        return identifiants;
    }

    void IdentifiantDaoImpl::insert(const model::Identifiant<> &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql_log = "INSERT INTO LOGIN(email, password) values (?, ?);";
        sqlite3_stmt *stmt_login = nullptr;

        if (sqlite3_prepare_v2(bd, sql_log.c_str(), -1, &stmt_login, nullptr) != SQLITE_OK) {
        	std::cerr << "Error preparing statement to insert LOGIN : \n" << sqlite3_errmsg(bd) << std::endl;
        	if (stmt_login) sqlite3_finalize(stmt_login);
        	return;
        }
    	sqlite3_bind_text(stmt_login, 1, item.getEmail().c_str(), -1, SQLITE_TRANSIENT);
    	sqlite3_bind_text(stmt_login, 2, item.getPassword().c_str(), -1, SQLITE_TRANSIENT);

    	if (sqlite3_step(stmt_login) != SQLITE_DONE) {
    		std::cerr << "Error insert LOGIN : \n" << sqlite3_errmsg(bd) << std::endl;
    		sqlite3_finalize(stmt_login);
    		return;
    	}
    	sqlite3_finalize(stmt_login);
    	std::cout << "inserted LOGIN" << std::endl;
    }

	void IdentifiantDaoImpl::addService(const int &service_id, const model::Identifiant<> &item) {
	    sqlite3 *bd = m_connector.getDB();
    	const std::string sql {"INSERT INTO USE(email, service_id) values(?, ?);"};
    	sqlite3_stmt *stmt = nullptr;

    	if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    		std::cerr << "Error preparing statement to insert USE : \n" << sqlite3_errmsg(bd) << std::endl;
    		if (stmt) sqlite3_finalize(stmt);
    		return;
    	}

    	sqlite3_bind_text(stmt, 1, item.getPassword().c_str(), -1, SQLITE_TRANSIENT);
    	sqlite3_bind_int(stmt, 2, service_id);
    	if (sqlite3_step(stmt) != SQLITE_DONE) {
    		std::cerr << "Error insert USE : \n" << sqlite3_errmsg(bd) << std::endl;
    		sqlite3_finalize(stmt);
    		return;
    	}

    	sqlite3_finalize(stmt);
    	std::cout << "added " << service_id << " to " << item.getId() << std::endl;
    }

    void IdentifiantDaoImpl::remove(const model::Identifiant<> &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "DELETE FROM LOGIN where id = ?";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Error preparing statement to delete LOGIN : \n" << sqlite3_errmsg(bd) << std::endl;
        	if (stmt) sqlite3_finalize(stmt);
        	return;
        }
    	sqlite3_bind_int(stmt, 1, item.getId());

    	if (sqlite3_step(stmt) != SQLITE_DONE) {
    		std::cerr << "Error delete LOGIN : \n" << sqlite3_errmsg(bd) << std::endl;
    		sqlite3_finalize(stmt);
    		return;
    	}

    	std::cout << "removed LOGIN" << std::endl;
    	sqlite3_finalize(stmt);
    }
} // impl