//
// Created by kracocks on 12/01/25.
//

#ifndef IDENTIFIANT_H
#define IDENTIFIANT_H
#include <string>
#include <bits/stl_vector.h>

namespace model {

    class Identifiant {
        std::string m_email;
        std::string m_password;

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
         * Compare two logins
         * @param other Login to compare
         * @return True if the two objects are the same
         */
        bool operator==(const Identifiant &other) const;
    };

} // model

#endif //IDENTIFIANT_H
