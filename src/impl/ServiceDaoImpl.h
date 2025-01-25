//
// Created by kracocks on 25/01/25.
//

#ifndef SERVICEDAOIMPL_H
#define SERVICEDAOIMPL_H
#include "../bd/Connector.h"
#include "../bd/IServiceDAO.h"

namespace impl {

    class ServiceDaoImpl final: public bd::IServiceDAO {
        bd::Connector &m_connector;

    public:
        explicit ServiceDaoImpl();

        ~ServiceDaoImpl() override = default;

        std::vector<model::Service> findAll() override;
        model::Service findByName(std::string &&name) override;
        model::Service findByName(const std::string &name) override;
        void insert(const model::Service &item) override;
        void remove(const model::Service &item) override;
    };

} // impl

#endif //SERVICEDAOIMPL_H
