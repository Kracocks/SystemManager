//
// Created by kracocks on 25/01/25.
//

#include "ServiceDaoImpl.h"

#include <iostream>

namespace impl {
    ServiceDaoImpl::ServiceDaoImpl(): m_connector(bd::Connector::getInstance()) {}

    std::vector<model::Service> ServiceDaoImpl::findAll() {
        std::vector<model::Service> services {};
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT nom FROM SERVICE;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v3(bd, sql.c_str(), -1, SQLITE_PREPARE_PERSISTENT, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all SERVICE" << std::endl;
            return services;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            auto service = model::Service(name);
            services.push_back(service);
        }

        sqlite3_finalize(stmt);

        return services;
    }

    model::Service ServiceDaoImpl::findByName(std::string &&name) {
        model::Service service{"Does not exists"};
        // TODO : remove it
        return service;
    }

    model::Service ServiceDaoImpl::findByName(const std::string &name) {
        model::Service service{"Does not exists"};
        // TODO : remove it
        return service;
    }

    void ServiceDaoImpl::insert(const model::Service &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "INSERT INTO SERVICE(nom) values (?);";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, item.getName().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to insert SERVICE" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "inserted SERVICE" << std::endl;
            sqlite3_finalize(stmt);
        }
    }

    void ServiceDaoImpl::remove(const model::Service &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "DELETE FROM SERVICE where nom = ?;";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            sqlite3_bind_text(stmt, 1, item.getName().c_str(), -1, SQLITE_STATIC);
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