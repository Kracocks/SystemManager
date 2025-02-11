//
// Created by kracocks on 22/01/25.
//

#ifndef ITOKENGROUPDAO_H
#define ITOKENGROUPDAO_H
#include "IGenericDao.h"
#include "../model/TokenGroup.h"

namespace bd {
    class ITokenGroupDao: public IGenericDAO<model::TokenGroup> {
    public:
        ~ITokenGroupDao() override;

        virtual std::vector<model::TokenGroup> findByName(const std::string &name) = 0;
        virtual std::vector<model::TokenGroup> findByName(std::string &&name) = 0;
    };
}

#endif //ITOKENGROUPDAO_H
