//
// Created by kracocks on 15/01/25.
//

#include <catch2/catch_all.hpp>

#include "Token.h"

TEST_CASE("Test the constructors of Token", "[token]") {
    const std::string value{"value"};
    const model::Token* token1 {new model::Token{"token1"}};
    const model::Token* token2 {new model::Token{value}};

    REQUIRE(token1 != nullptr);
    REQUIRE(token2 != nullptr);
}

TEST_CASE("Test the getter of Token", "[token]") {
    const model::Token token{"token1"};

    REQUIRE(token.getValue() == "token1");
    REQUIRE(token.getValue() != "value");
}

TEST_CASE("Test the setters of Token", "[token]") {
    model::Token token{"token1"};
    token.setValue("token2");

    REQUIRE(token.getValue() == "token2");
    REQUIRE(token.getValue() != "token1");
}

TEST_CASE("Test operator==", "[token]") {
    model::Token token1{"value1"};
    model::Token token2{"value1"};
    model::Token token3{"value2"};

    REQUIRE(token1 == token2);
    REQUIRE(token1 != token3);
    REQUIRE(token2 != token3);
}