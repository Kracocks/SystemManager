//
// Created by kracocks on 22/01/25.
//

#ifndef ISERVICEDAO_H
#define ISERVICEDAO_H
#include "IGenericDao.h"
#include "../model/Service.h"

namespace bd {
    class IServiceDAO: public IGenericDAO<model::Service>{
    public:
        ~IServiceDAO() override;

        virtual model::Service findByName(const std::string &name) = 0;
        virtual model::Service findByName(std::string &&name) = 0;
    };
}

#endif //ISERVICEDAO_H
