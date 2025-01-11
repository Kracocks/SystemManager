

#ifndef CONNECTOR_H
#define CONNECTOR_H

namespace bd {

class Connector {
    sqlite3 *m_bd{};

public:
    Connector(const std::string &dbFilePath, const std::string &key);
    ~Connector();
    [[nodiscard]] sqlite3 *getDB() const;
};

} // bd

#endif //CONNECTOR_H
