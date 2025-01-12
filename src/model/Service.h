//
// Created by kracocks on 11/01/25.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <vector>

#include "Identifiant.h"

namespace model {

    class Service {
        std::string m_name;
        std::vector<Identifiant> m_identifiants;

    public:
        Service() = delete;
        explicit Service(const std::string &name);
        explicit Service(std::string &&name);

        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::vector<Identifiant> getIdentifiants() const;

        void setName(const std::string &name);
        void setName(std::string &&name);

        void addIdentifiant(const Identifiant &identifiant);
        void addIdentifiant(Identifiant &&identifiant);
        void removeIdentifiant(const Identifiant &identifiant);
        void removeIdentifiant(Identifiant &&identifiant);
    };

} // model

#endif //SERVICE_H
