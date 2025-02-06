//
// Created by kracocks on 15/01/25.
//

#include <catch2/catch_all.hpp>

#include "Token.h"

TEST_CASE("Test the constructors of Token", "[token]") {
    const std::string value{"value"};
    const model::Token* token1 {new model::Token{0, "token1"}};
    const model::Token* token2 {new model::Token{1, value}};

    REQUIRE(token1 != nullptr);
    REQUIRE(token2 != nullptr);
}

TEST_CASE("Test the getter of Token", "[token]") {
    const model::Token token{0, "token1"};

    REQUIRE(token.value == "token1");
    REQUIRE(token.value != "value");
}

TEST_CASE("Test the setters of Token", "[token]") {
    model::Token token{0, "token1"};
    token.value = "token2";

    REQUIRE(token.value == "token2");
    REQUIRE(token.value != "token1");
}