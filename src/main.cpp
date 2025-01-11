#include <iostream>
#include <sqlite3.h>

#include "./bd/Connector.h"

int main() {
    const std::string db_path = "passwords.sqlite";
    const std::string db_key = std::getenv("DB_KEY");

    bd::Connector& db = bd::Connector::getInstance();
    if (db.getDB()) {
        std::cout << "ok" << std::endl;
    } else {
        std::cerr << "Failed to open db" << std::endl;
        return 1;
    }
    return 0;
}