//
// Created by kracocks on 12/01/25.
//

#ifndef IDENTIFIANT_H
#define IDENTIFIANT_H
#include <string>

namespace model {

    class Identifiant {
        std::string m_email;
        std::string m_password;

    public:
        Identifiant() = delete;
        Identifiant(const std::string &email, const std::string &password);
        Identifiant(std::string &&email, std::string &&password);
        Identifiant(const std::string &email, std::string &&password);
        Identifiant(std::string &&email, const std::string &password);

        [[nodiscard]] std::string getEmail() const;
        [[nodiscard]] std::string getPassword() const;

        void setEmail(const std::string &email);
        void setEmail(std::string &&email);
        void setPassword(const std::string &password);
        void setPassword(std::string &&password);
    };

} // model

#endif //IDENTIFIANT_H
