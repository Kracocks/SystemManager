//
// Created by kracocks on 24/01/25.
//

#ifndef IDENTIFIANTDAOIMPL_H
#define IDENTIFIANTDAOIMPL_H
#include <vector>
#include "../bd/Connector.h"
#include "../bd/IGenericDao.h"
#include "../model/Identifiant.h"

namespace impl {

    class IdentifiantDaoImpl final : public bd::IGenericDAO<model::Identifiant<>> {
        bd::Connector &m_connector;

    public:
        explicit IdentifiantDaoImpl();

        ~IdentifiantDaoImpl() override = default;

        std::vector<model::Identifiant<>> findAll() override;
        std::vector<model::Identifiant<>> findByEmail(std::string &&email);
        std::vector<model::Identifiant<>> findByEmail(const std::string &email);
        void insert(const model::Identifiant<> &item) override;
    	void addService(const int &service, const model::Identifiant<> &login);
        void remove(const model::Identifiant<> &item) override;
    };

} // impl

#endif //IDENTIFIANTDAOIMPL_H
