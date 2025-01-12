//
// Created by kracocks on 12/01/25.
//

#include "Token.h"

namespace model {
    Token::Token(const std::string &value): m_value(value) {
    }

    Token::Token(std::string &&value): m_value(std::move(value)) {
    }

    std::string Token::getValue() const {
        return m_value;
    }

    void Token::setValue(const std::string &value) {
        m_value = value;
    }

    void Token::setValue(std::string &&value) {
        m_value = std::move(value);
    }

    bool Token::operator==(const Token &token) const {
        return m_value == token.m_value;
    }
} // model
