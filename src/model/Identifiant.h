//
// Created by kracocks on 12/01/25.
//

#ifndef IDENTIFIANT_H
#define IDENTIFIANT_H
#include <string>

#include "Service.h"

namespace model {

    class Identifiant {
        int m_id{-1};
        std::string m_email;
        std::string m_password;
        std::vector<model::Service> m_services;

    public:
        Identifiant() = delete;
        /**
         * Create a login with an email and a password
         * @param email Email of the login
         * @param password password of the login
         */
        Identifiant(const std::string &email, const std::string &password);
        /**
         * Create a login with an email and a password
         * @param email Email of the login
         * @param password Password of the login
         */
        Identifiant(std::string &&email, std::string &&password);
        /**
         * Create a login with an email and a password
         * @param email Email of the login
         * @param password Password of the login
         */
        Identifiant(const std::string &email, std::string &&password);
        /**
         * Create a login with an email and a password
         * @param email Email of the login
         * @param password Password of the login
         */
        Identifiant(std::string &&email, const std::string &password);

        /**
         * Get the ID of the login
         * @return ID of the login
         */
        [[nodiscard]] int getId() const;

        /**
         * Get the email of the login
         * @return Email of the login
         */
        [[nodiscard]] std::string getEmail() const;

        /**
         * Get the password of the login
         * @return Password of the login
         */
        [[nodiscard]] std::string getPassword() const;

        /**
         * Get the Services associated to the login
         * @return Services associated to the login
         */
        [[nodiscard]] std::vector<Service> getServices() const;

        /**
         * Set the ID of the login
         * @param id New ID of the login
         */
        void setID(const int &id);

        /**
         * Set the ID of the login
         * @param id New ID of the login
         */
        void setID(int &&id);

        /**
         * Set the email of the login
         * @param email New email of the login
         */
        void setEmail(const std::string &email);
        /**
         * Set the email of the login
         * @param email New email of the login
         */
        void setEmail(std::string &&email);
        /**
         * Set the password of the login
         * @param password New password of the login
         */
        void setPassword(const std::string &password);
        /**
         * Set the password of the login
         * @param password New password of the login
         */
        void setPassword(std::string &&password);

        /**
         * Add a new service to the login
         * @param service New service to associate to the login
         */
        void addService(const Service &service);

        /**
         * Add a new service to the login
         * @param service New service to associate to the login
         */
        void addService(Service &&service);

        /**
         * Remove a service associated to the login
         * @param service Service associated to the login
         */
        void removeService(const Service &service);

        /**
         * Remove a service associated to the login
         * @param service Service associated to the login
         */
        void removeService(Service &&service);

        /**
         * Compare two logins
         * @param other Login to compare
         * @return True if the two objects are the same
         */
        bool operator==(const Identifiant &other) const;
    };

} // model

#endif //IDENTIFIANT_H
