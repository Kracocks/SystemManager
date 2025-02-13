//
// Created by kracocks on 25/01/25.
//

#ifndef TOKENGROUPDAOIMPL_H
#define TOKENGROUPDAOIMPL_H

#include "../bd/Connector.h"
#include "../bd/ITokenGroupDAO.h"

namespace impl {

    class TokenGroupDaoImpl final: public bd::ITokenGroupDAO{
        std::vector<model::TokenGroup> m_tokenGroups;
        bd::Connector &m_connector;

    public:
        explicit TokenGroupDaoImpl();

        ~TokenGroupDaoImpl() override = default;

        std::vector<model::TokenGroup> findAll() override;
        std::vector<model::TokenGroup> findByName(std::string &&name) override;
        std::vector<model::TokenGroup> findByName(const std::string &name) override;
        void insert(const model::TokenGroup &item) override;
        void remove(const model::TokenGroup &item) override;
    };

} // impl

#endif //TOKENGROUPDAOIMPL_H
