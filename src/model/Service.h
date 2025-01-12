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
        /**
         * Create a service with a name
         * @param name Name of the service
         */
        explicit Service(const std::string &name);
        /**
         * Create a service with a name
         * @param name Name of the service
         */
        explicit Service(std::string &&name);

        /**
         * Get the name of the service
         * @return Name of the service
         */
        [[nodiscard]] std::string getName() const;
        /**
         * Get the logins associated to the service
         * @return Logins associated to the service
         */
        [[nodiscard]] std::vector<Identifiant> getIdentifiants() const;
        /**
         * Get the groups of token associated to the service
         * @return Groups of token associated to the service
         */
        [[nodiscard]] std::vector<TokenGroup> getTokenGroups() const;

        /**
         * Set the name of the service
         * @param name New name of the service
         */
        void setName(const std::string &name);
        /**
         * Set the name of the service
         * @param name New name of the service
         */
        void setName(std::string &&name);

        /**
         * Add a login in the service
         * @param identifiant New login in the service
         */
        void addIdentifiant(const Identifiant &identifiant);
        /**
         * Add a login in the service
         * @param identifiant New login in the service
         */
        void addIdentifiant(Identifiant &&identifiant);
        /**
         * Remove a login from the service
         * @param identifiant Login to remove from the service
         */
        void removeIdentifiant(const Identifiant &identifiant);
        /**
         * Remove a login from the service
         * @param identifiant Login to remove from the service
         */
        void removeIdentifiant(Identifiant &&identifiant);

        /**
         * Add a group of tokens
         * @param tokenGroup Group of tokens to add
         */
        void addTokenGroup(const TokenGroup &tokenGroup);
        /**
         * Add a group of tokens
         * @param tokenGroup Group of tokens to add
         */
        void addTokenGroup(TokenGroup &&tokenGroup);
        /**
         * Remove a group of tokens
         * @param tokenGroup Group of tokens to remove
         */
        void removeTokenGroup(const TokenGroup &tokenGroup);
        /**
         * Remove a group of tokens
         * @param tokenGroup Group of tokens to remove
         */
        void removeTokenGroup(TokenGroup &&tokenGroup);
    };
} // model

#endif //SERVICE_H
