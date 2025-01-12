//
// Created by kracocks on 12/01/25.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>

namespace model {
    class Token {
        std::string m_value;
    public:
        /**
         * Create a token with a value
         * @param value Value of the token
         */
        explicit Token(const std::string &value);
        /**
         * Create a token with a value
         * @param value Value of the token
         */
        explicit Token(std::string &&value);

        /**
         * Get the value of the token
         * @return Value of the token
         */
        [[nodiscard]] std::string getValue() const;

        /**
         * Set the value of the token
         * @param value New value of the token
         */
        void setValue(const std::string &value);
        /**
         * Set the value of the token
         * @param value New value of the token
         */
        void setValue(std::string &&value);

        /**
         * Compare two tokens
         * @param token Token to compare
         * @return True if the two objects are the same
         */
        bool operator==(const Token &token) const;
    };
} // model

#endif //TOKEN_H
