//
// Created by kracocks on 11/01/25.
//

#include "Service.h"

namespace model {
    Service::Service(const std::string &name): m_name(name) {
    }

    Service::Service(std::string &&name): m_name(name) {
    }

    std::string Service::getName() const {
        return m_name;
    }

    std::vector<Identifiant> Service::getIdentifiants() const {
        return m_identifiants;
    }

    std::vector<TokenGroup> Service::getTokenGroups() const {
        return m_tokenGroups;
    }

    void Service::setName(const std::string &name) {
        m_name = name;
    }

    void Service::setName(std::string &&name) {
        m_name = name;
    }

    void Service::addIdentifiant(const Identifiant &identifiant) {
        m_identifiants.push_back(identifiant);
    }

    void Service::addIdentifiant(Identifiant &&identifiant) {
        m_identifiants.push_back(std::move(identifiant));
    }

    void Service::removeIdentifiant(const Identifiant &identifiant) {
        for (int i = 0; i < m_identifiants.size(); ++i) {
            if (m_identifiants.at(i) == identifiant) {
                m_identifiants.erase(m_identifiants.begin() + i);
            }
        }
    }

    void Service::removeIdentifiant(Identifiant &&identifiant) {
        for (int i = 0; i < m_identifiants.size(); ++i) {
            if (m_identifiants.at(i) == identifiant) {
                m_identifiants.erase(m_identifiants.begin() + i);
            }
        }
    }

    void Service::addTokenGroup(const TokenGroup &tokenGroup) {
        m_tokenGroups.push_back(tokenGroup);
    }

    void Service::addTokenGroup(TokenGroup &&tokenGroup) {
        m_tokenGroups.push_back(std::move(tokenGroup));
    }

    void Service::removeTokenGroup(const TokenGroup &tokenGroup) {
        for (int i {0}; i < m_tokenGroups.size(); ++i) {
            if (m_tokenGroups.at(i) == tokenGroup) {
                m_tokenGroups.erase(m_tokenGroups.begin() + i);
            }
        }
    }

    void Service::removeTokenGroup(TokenGroup &&tokenGroup) {
        for (int i {0}; i < m_tokenGroups.size(); ++i) {
            if (m_tokenGroups.at(i) == tokenGroup) {
                m_tokenGroups.erase(m_tokenGroups.begin() + i);
            }
        }
    }
} // model