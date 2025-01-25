//
// Created by kracocks on 25/01/25.
//

#include "TokenGroupDaoImpl.h"

#include <iostream>

namespace impl {
    TokenGroupDaoImpl::TokenGroupDaoImpl(): m_connector(bd::Connector::getInstance()) {}

    std::vector<model::TokenGroup> TokenGroupDaoImpl::findAll() {
        std::vector<model::TokenGroup> tokenGroups;
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT nom_groupe FROM TOKEN_GROUP;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v3(bd, sql.c_str(), -1, SQLITE_PREPARE_PERSISTENT, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all TOKEN_GROUP" << std::endl;
            return tokenGroups;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto groupName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            model::TokenGroup tokenGroup{groupName};
            tokenGroups.push_back(tokenGroup);
        }

        sqlite3_finalize(stmt);

        return tokenGroups;
    }

    model::TokenGroup TokenGroupDaoImpl::findByName(std::string &&name) {
        model::TokenGroup tokenGroup{"Does not have a name"};
        // TODO : remake it
        return tokenGroup;
    }

    model::TokenGroup TokenGroupDaoImpl::findByName(const std::string &name) {
        model::TokenGroup tokenGroup{"Does not have a name"};
        // TODO : remake it
        return tokenGroup;
    }

    void TokenGroupDaoImpl::insert(const model::TokenGroup &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "INSERT INTO TOKEN_GROUP(id_service, nom_groupe) values (?, ?);";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            constexpr int id_service {};
            sqlite3_bind_int(stmt, 1, id_service);
            sqlite3_bind_text(stmt, 2, item.getName().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to insert TOKEN_GROUP" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "inserted TOKEN_GROUP" << std::endl;
            sqlite3_finalize(stmt);
        }
    }

    void TokenGroupDaoImpl::remove(const model::TokenGroup &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "DELETE FROM TOKEN_GROUP where id_service = ? and nom_groupe = ?;";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            constexpr int id_service {};
            sqlite3_bind_int(stmt, 1, id_service);
            sqlite3_bind_text(stmt, 2, item.getName().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to remove TOKEN_GROUP" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "removed TOKEN_GROUP" << std::endl;
            sqlite3_finalize(stmt);
        }
    }





} // impl