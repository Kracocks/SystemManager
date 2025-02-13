//
// Created by kracocks on 22/01/25.
//

#ifndef ITOKENGROUPDAO_H
#define ITOKENGROUPDAO_H
#include "../model/TokenGroup.h"
#include "IGenericDao.h"

namespace bd {
    class ITokenGroupDAO: public IGenericDAO<model::TokenGroup> {
    public:
        ~ITokenGroupDAO() override;

        virtual std::vector<model::TokenGroup> findByName(const std::string &name) = 0;
        virtual std::vector<model::TokenGroup> findByName(std::string &&name) = 0;
    };
}

#endif //ITOKENGROUPDAO_H
