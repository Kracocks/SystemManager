//
// Created by kracocks on 12/01/25.
//

#include "TokenGroup.h"

#include <algorithm>

namespace model {
    TokenGroup::TokenGroup(const std::string &name): m_name(name) {
    }

    TokenGroup::TokenGroup(std::string &&name): m_name(std::move(name)) {
    }

    std::string TokenGroup::getName() const {
        return m_name;
    }

    std::vector<Token> TokenGroup::getTokens() const {
        return m_tokens;
    }

    void TokenGroup::setName(const std::string &name) {
        m_name = name;
    }

    void TokenGroup::setName(std::string &&name) {
        m_name = std::move(name);
    }

    void TokenGroup::addToken(const Token &token) {
        m_tokens.push_back(token);
    }

    void TokenGroup::addToken(Token &&token) {
        m_tokens.push_back(std::move(token));
    }

    void TokenGroup::removeToken(const Token &token) {
        for (int i {0}; i < m_tokens.size(); i++) {
            if (m_tokens.at(i) == token) {
                m_tokens.erase(m_tokens.begin() + i);
            }
        }
    }

    void TokenGroup::removeToken(Token &&token) {
        for (int i {0}; i < m_tokens.size(); i++) {
            if (m_tokens.at(i) == token) {
                m_tokens.erase(m_tokens.begin() + i);
            }
        }
    }

    bool TokenGroup::operator==(const TokenGroup  &token_group) const {
        if (m_name == token_group.m_name) {
            if (m_tokens.size() == token_group.m_tokens.size()) {
                for (int i {0}; i < m_tokens.size(); i++) {
                    if (m_tokens.at(i) != token_group.m_tokens.at(i)) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
} // model