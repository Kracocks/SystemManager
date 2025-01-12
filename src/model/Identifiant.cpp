//
// Created by kracocks on 12/01/25.
//

#include "Identifiant.h"

namespace model {
    Identifiant::Identifiant(const std::string &email, const std::string &password)
        : m_email(email), m_password(password) {
    }

    Identifiant::Identifiant(std::string &&email, std::string &&password)
        : m_email(std::move(email)), m_password(std::move(password)) {
    }

    Identifiant::Identifiant(const std::string &email, std::string &&password)
        : m_email(email), m_password(std::move(password)) {
    }

    Identifiant::Identifiant(std::string &&email, const std::string &password)
        : m_email(std::move(email)), m_password(password) {
    }

    std::string Identifiant::getEmail() const {
        return m_email;
    }

    std::string Identifiant::getPassword() const {
        return m_password;
    }

    void Identifiant::setEmail(const std::string &email) {
        m_email = email;
    }

    void Identifiant::setEmail(std::string &&email) {
        m_email = std::move(email);
    }

    void Identifiant::setPassword(const std::string &password) {
        m_password = password;
    }

    void Identifiant::setPassword(std::string &&password) {
        m_password = std::move(password);
    }

    bool Identifiant::operator==(const Identifiant &other) const {
        return m_email == other.m_email && m_password == other.m_password;
    }
} // model