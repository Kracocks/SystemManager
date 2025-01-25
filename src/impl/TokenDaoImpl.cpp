//
// Created by kracocks on 25/01/25.
//

#include "TokenDaoImpl.h"

#include <iostream>

namespace impl {
    TokenDaoImpl::TokenDaoImpl(): m_connector(bd::Connector::getInstance()) {}

    std::vector<model::Token> TokenDaoImpl::findAll() {
        std::vector<model::Token> tokens;
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "SELECT val FROM TOKEN;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v3(bd, sql.c_str(), -1, SQLITE_PREPARE_PERSISTENT, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all TOKEN" << std::endl;
            return tokens;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto value = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            model::Token token{value};
            tokens.push_back(token);
        }

        sqlite3_finalize(stmt);

        return tokens;
    }

    model::Token TokenDaoImpl::findByValue(std::string &&value) {
        // TODO : remake it
        return model::Token{"Does not exist"};
    }

    model::Token TokenDaoImpl::findByValue(const std::string &value) {
        // TODO : remake it
        return model::Token{"Does not exist"};
    }

    void TokenDaoImpl::insert(const model::Token &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "INSERT INTO TOKEN(id_token_group, valeur_token) values (?, ?);";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            int idTokenGroup = 0;
            sqlite3_bind_int(stmt, 1, idTokenGroup);
            sqlite3_bind_text(stmt, 2, item.getValue().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to insert TOKEN" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "inserted TOKEN" << std::endl;
            sqlite3_finalize(stmt);
        }
    }

    void TokenDaoImpl::remove(const model::Token &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "DELETE FROM TOKEN where id_token_group = ? and valeur_token = ?;";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            int idTokenGroup = 0;
            sqlite3_bind_int(stmt, 1, idTokenGroup);
            sqlite3_bind_text(stmt, 2, item.getValue().c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) != SQLITE_DONE) {
                std::cerr << "Error preparing statement to remove TOKEN" << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            std::cout << "removed TOKEN" << std::endl;
            sqlite3_finalize(stmt);
        }
    }

} // impl