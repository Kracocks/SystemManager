//
// Created by kracocks on 16/01/25.
//

#ifndef IDENTIFIANTDAO_H
#define IDENTIFIANTDAO_H
#include <string>
#include <vector>

#include "../model/Identifiant.h"


namespace bd{
    class IdentifiantDao {
    public:
        IdentifiantDao();
        virtual ~IdentifiantDao();

        virtual std::vector<model::Identifiant> getIdentifiant() = 0;
        virtual std::vector<model::Identifiant> getIdentifiantsByEmail(std::string email) = 0;
        virtual void saveIdentifiant(model::Identifiant) = 0;
        virtual void deleteIdentifiant(model::Identifiant) = 0;
    };
}



#endif IDENTIFIANTDAO_H
