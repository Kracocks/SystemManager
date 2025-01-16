//
// Created by kracocks on 16/01/25.
//

#ifndef TOKENDAO_H
#define TOKENDAO_H
#include <vector>

#include "../model/Token.h"

namespace bd {
    class TokenDao {
    public:
        TokenDao();
        virtual ~TokenDao();

        virtual std::vector<model::Token> getTokens() = 0;
        virtual void saveToken(model::Token token);
        virtual void deleteToken(model::Token token);
    };

} // bd

#endif TOKENDAO_H
