//
// Created by kracocks on 12/01/25.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <bits/stl_vector.h>

namespace model {
    class Token {
        std::string m_value;
    public:
        explicit Token(const std::string &value);
        explicit Token(std::string &&value);

        [[nodiscard]] std::string getValue() const;

        void setValue(const std::string &value);
        void setValue(std::string &&value);

        bool operator==(const Token &token) const;
    };
} // model

#endif //TOKEN_H
