//
// Created by kracocks on 22/01/25.
//

#ifndef ISERVICEDAO_H
#define ISERVICEDAO_H
#include "IGenericDao.h"
#include "../model/Service.h"

namespace bd {
    class IServiceDao: public IGenericDAO<model::Service>{
    public:
        ~IServiceDao() override;

        virtual std::vector<model::Service> findByName(const std::string &name) = 0;
        virtual std::vector<model::Service> findByName(std::string &&name) = 0;
    };
}

#endif //ISERVICEDAO_H
