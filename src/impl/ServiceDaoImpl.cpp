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
        const std::string sql = "SELECT service_id, nom FROM SERVICE;";
        sqlite3_stmt *stmt;

        int status = sqlite3_prepare_v3(bd, sql.c_str(), -1, SQLITE_PREPARE_PERSISTENT, &stmt, nullptr);
        if (status != SQLITE_OK) {
            std::cerr << "Error preparing statement to get all SERVICE" << std::endl;
            return services;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
        	model::Service service = model::Service(
				sqlite3_column_int(stmt, 0),
				reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
            services.push_back(service);
        }

        sqlite3_finalize(stmt);

        return services;
    }

	std::vector<model::Service> ServiceDaoImpl::findByName(std::string &&name) {
    	std::vector<model::Service> services;
    	sqlite3 *bd = m_connector.getDB();
    	const std::string sql = "SELECT service_id, name FROM SERVICE where email LIKE ?;";
    	sqlite3_stmt *stmt;

    	int status = sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr);
    	if (status != SQLITE_OK) {
    		std::cerr << "Error preparing statement to get all SERVICE by email : \n" << sqlite3_errmsg(bd) << std::endl;
    		if (stmt) sqlite3_finalize(stmt);
    		return services;
    	}
    	sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);

    	while (sqlite3_step(stmt) == SQLITE_ROW) {
			model::Service service {
				sqlite3_column_int(stmt, 0),
				reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))};
    		services.push_back(service);
    	}

    	sqlite3_finalize(stmt);
    	return services;
    }

	std::vector<model::Service> ServiceDaoImpl::findByName(const std::string &name) {
    	std::vector<model::Service> services;
    	sqlite3 *bd = m_connector.getDB();
    	const std::string sql = "SELECT service_id, name FROM SERVICE where email LIKE ?;";
    	sqlite3_stmt *stmt;

    	int status = sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr);
    	if (status != SQLITE_OK) {
    		std::cerr << "Error preparing statement to get all SERVICE by email : \n" << sqlite3_errmsg(bd) << std::endl;
    		if (stmt) sqlite3_finalize(stmt);
    		return services;
    	}
    	sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);

    	while (sqlite3_step(stmt) == SQLITE_ROW) {
    		model::Service service {
    			sqlite3_column_int(stmt, 0),
				reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1))};
    		services.push_back(service);
    	}

    	sqlite3_finalize(stmt);
    	return services;
	}

    void ServiceDaoImpl::insert(const model::Service &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "INSERT INTO SERVICE(nom) values (?);";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        	std::cerr << "Error preparing statement to insert SERVICE" << std::endl;
        	sqlite3_finalize(stmt);
        	return;
        }
    	sqlite3_bind_text(stmt, 1, item.name.c_str(), -1, SQLITE_STATIC);

    	if (sqlite3_step(stmt) != SQLITE_DONE) {
    		std::cerr << "Error inserting SERVICE" << std::endl;
    		sqlite3_finalize(stmt);
    		return;
    	}

    	std::cout << "inserted SERVICE" << std::endl;
    	sqlite3_finalize(stmt);
    }

    void ServiceDaoImpl::remove(const model::Service &item) {
        sqlite3 *bd = m_connector.getDB();
        const std::string sql = "DELETE FROM SERVICE where id = ?;";
        sqlite3_stmt *stmt = nullptr;

        if (sqlite3_prepare_v2(bd, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        	std::cerr << "Error preparing statement to remove IDENTIFIANT" << std::endl;
        	sqlite3_finalize(stmt);
        	return;
        }
    	sqlite3_bind_text(stmt, 1, std::to_string(item.id).c_str(), -1, SQLITE_STATIC);

    	if (sqlite3_step(stmt) != SQLITE_DONE) {
    		std::cerr << "Error removing IDENTIFIANT" << std::endl;
    		sqlite3_finalize(stmt);
    		return;
    	}

    	std::cout << "removed IDENTIFIANT" << std::endl;
    	sqlite3_finalize(stmt);
    }




} // impl