//
// Created by kracocks on 11/01/25.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <vector>

#include "Identifiant.h"
#include "TokenGroup.h"

namespace model {

    class Service {
        std::string m_name;
        std::vector<Identifiant> m_identifiants;
        std::vector<TokenGroup> m_tokenGroups;

    public:
        Service() = delete;
        explicit Service(const std::string &name);
        explicit Service(std::string &&name);

        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::vector<Identifiant> getIdentifiants() const;
        [[nodiscard]] std::vector<TokenGroup> getTokenGroups() const;

        void setName(const std::string &name);
        void setName(std::string &&name);

        void addIdentifiant(const Identifiant &identifiant);
        void addIdentifiant(Identifiant &&identifiant);
        void removeIdentifiant(const Identifiant &identifiant);
        void removeIdentifiant(Identifiant &&identifiant);

        void addTokenGroup(const TokenGroup &tokenGroup);
        void addTokenGroup(TokenGroup &&tokenGroup);
        void removeTokenGroup(const TokenGroup &tokenGroup);
        void removeTokenGroup(TokenGroup &&tokenGroup);
    };
} // model

#endif //SERVICE_H
