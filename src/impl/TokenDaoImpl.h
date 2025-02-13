//
// Created by kracocks on 25/01/25.
//

#ifndef TOKENDAOIMPL_H
#define TOKENDAOIMPL_H
#include "../bd/Connector.h"
#include "../bd/ITokenDao.h"
#include "../bd/ITokenGroupDAO.h"

namespace impl {

    class TokenDaoImpl final: public bd::IITokenDao {
        bd::Connector &m_connector;

    public:
        explicit TokenDaoImpl();
        ~TokenDaoImpl() override = default;

        std::vector<model::Token> findAll() override;
        std::vector<model::Token> findByValue(std::string &&value) override;
        std::vector<model::Token> findByValue(const std::string &value) override;
        void insert(const model::Token &item) override;
        void remove(const model::Token &item) override;
    };

} // impl

#endif //TOKENDAOIMPL_H
