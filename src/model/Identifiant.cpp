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

    int Identifiant::getId() const {
        return m_id;
    }

    std::string Identifiant::getEmail() const {
        return m_email;
    }

    std::string Identifiant::getPassword() const {
        return m_password;
    }

    std::vector<Service> Identifiant::getServices() const {
        return m_services;
    }

    void Identifiant::setID(const int &id) {
        m_id = id;
    }

    void Identifiant::setID(int &&id) {
        m_id = id;
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

    void Identifiant::addService(const Service &service) {
        m_services.push_back(service);
    }

    void Identifiant::addService(Service &&service) {
        m_services.push_back(std::move(service));
    }

    bool Identifiant::operator==(const Identifiant &other) const {
        return m_email == other.m_email && m_password == other.m_password;
    }
} // model