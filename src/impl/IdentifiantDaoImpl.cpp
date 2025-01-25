//
// Created by kracocks on 24/01/25.
//

#include "IdentifiantDaoImpl.h"

#include <iostream>
#include <ostream>

namespace impl {
    IdentifiantDaoImpl::IdentifiantDaoImpl(): m_connector(bd::Connector::getInstance()) {}

    std::vector<model::Identifiant> IdentifiantDaoImpl::findAll() {
        std::vector<model::Identifiant> identifiants;
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT email, password FROM IDENTIFIANT;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v3(bd, sql.c_str(), -1, SQLITE_PREPARE_PERSISTENT, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all IDENTIFIANT" << std::endl;
            return identifiants;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto email = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            const auto password = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            model::Identifiant identifiant = model::Identifiant(email, password);
            identifiants.push_back(identifiant);
        }

        sqlite3_finalize(stmt);

        return identifiants;
    }

    std::vector<model::Identifiant> IdentifiantDaoImpl::findByEmail(std::string &&email) {
        std::vector<model::Identifiant> identifiants;
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT password FROM IDENTIFIANT;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all IDENTIFIANT" << std::endl;
            return identifiants;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto password = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            model::Identifiant identifiant = model::Identifiant(email, password);
            identifiants.push_back(identifiant);
        }

        sqlite3_finalize(stmt);
        return identifiants;
    }

    std::vector<model::Identifiant> IdentifiantDaoImpl::findByEmail(const std::string &email) {
        std::vector<model::Identifiant> identifiants;
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT password FROM IDENTIFIANT;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all IDENTIFIANT" << std::endl;
            sqlite3_finalize(stmt);
            return identifiants;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto password = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            model::Identifiant identifiant = model::Identifiant(email, password);
            identifiants.push_back(identifiant);
        }

        sqlite3_finalize(stmt);
        return identifiants;
    }

    void IdentifiantDaoImpl::insert(const model::Identifiant &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "INSERT INTO IDENTIFIANT(email, password) values (?, ?);";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, item.getEmail().c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, item.getPassword().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to insert IDENTIFIANT" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "inserted IDENTIFIANT" << std::endl;
            sqlite3_finalize(stmt);
        }
    }

    void IdentifiantDaoImpl::remove(const model::Identifiant &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "DELETE FROM IDENTIFIANT where email = ? and password = ?;";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, item.getEmail().c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, item.getPassword().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to remove IDENTIFIANT" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "removed IDENTIFIANT" << std::endl;
            sqlite3_finalize(stmt);
        }
    }
} // impl