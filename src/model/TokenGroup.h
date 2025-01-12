//
// Created by kracocks on 12/01/25.
//

#ifndef TOKENGROUP_H
#define TOKENGROUP_H
#include <string>
#include <vector>

#include "Token.h"

namespace model {

    class TokenGroup {
        std::string m_name;
        std::vector<Token> m_tokens;

    public:
        explicit TokenGroup(const std::string &name);
        explicit TokenGroup(std::string &&name);

        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::vector<Token> getTokens() const;

        void setName(const std::string &name);
        void setName(std::string &&name);

        void addToken(const Token &token);
        void addToken(Token &&token);
        void removeToken(const Token &token);
        void removeToken(Token &&token);

        bool operator==(const TokenGroup &token_group) const;
    };
} // model

#endif //TOKENGROUP_H
