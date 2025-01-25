//
// Created by kracocks on 24/01/25.
//

#ifndef IDENTIFIANTDAOIMPL_H
#define IDENTIFIANTDAOIMPL_H

#include "../bd/Connector.h"
#include "../bd/IIdentifiantDao.h"

namespace impl {

    class IdentifiantDaoImpl final : public bd::IIdentifiantDao {
        std::vector<model::Identifiant> m_identifiants;
        bd::Connector &m_connector;

    public:
        explicit IdentifiantDaoImpl();

        ~IdentifiantDaoImpl() override = default;

        std::vector<model::Identifiant> findAll() override;
        std::vector<model::Identifiant> findByEmail(std::string &&email) override;
        std::vector<model::Identifiant> findByEmail(const std::string &email) override;
        void insert(const model::Identifiant &item) override;
        void remove(const model::Identifiant &item) override;
    };

} // impl

#endif //IDENTIFIANTDAOIMPL_H
