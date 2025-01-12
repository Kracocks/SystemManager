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
        /**
         * Create a group of token with a name
         * @param name Name of the group of tokens
         */
        explicit TokenGroup(const std::string &name);
        /**
         * Create a group of token with a name
         * @param name Name of the group of tokens
         */
        explicit TokenGroup(std::string &&name);

        /**
         * Get the name of the group
         * @return Name of the group of tokens
         */
        [[nodiscard]] std::string getName() const;
        /**
         * Get the tokens in the group
         * @return Tokens stocked in the group
         */
        [[nodiscard]] std::vector<Token> getTokens() const;

        /**
         * Set the name of the group
         * @param name New name for the group
         */
        void setName(const std::string &name);
        /**
         * Set the name of the group
         * @param name New name for the group
         */
        void setName(std::string &&name);

        /**
         * Add a token in the group
         * @param token Token added in the group
         */
        void addToken(const Token &token);
        /**
         * Add a token in the group
         * @param token Token added in the group
         */
        void addToken(Token &&token);
        /**
         * Remove a specific token from the group
         * @param token The token to remove
         */
        void removeToken(const Token &token);
        /**
         * Remove a specific token from the group
         * @param token The token to remove
         */
        void removeToken(Token &&token);

        /**
         * Compare two groups of tokens
         * @param token_group Group to compare
         * @return True if the two objects are the same
         */
        bool operator==(const TokenGroup &token_group) const;
    };
} // model

#endif //TOKENGROUP_H
