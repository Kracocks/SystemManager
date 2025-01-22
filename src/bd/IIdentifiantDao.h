//
// Created by kracocks on 16/01/25.
//

#ifndef IDENTIFIANTDAO_H
#define IDENTIFIANTDAO_H
#include <string>
#include <vector>

#include "IGenericDao.h"
#include "../model/Identifiant.h"


namespace bd{
    class IIdentifiantDao: public IGenericDAO<IIdentifiantDao>{
    public:
        ~IIdentifiantDao() override;

        virtual std::vector<model::Identifiant> findByEmail(const std::string &email) = 0;
        virtual std::vector<model::Identifiant> findByEmail(std::string &&email) = 0;
    };
}



#endif IDENTIFIANTDAO_H
