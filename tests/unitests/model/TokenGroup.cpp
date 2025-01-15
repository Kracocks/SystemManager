//
// Created by kracocks on 15/01/25.
//

#include <catch2/catch_all.hpp>

#include "Token.h"
#include "TokenGroup.h"

TEST_CASE("Test the constructors of TokenGroup", "[tokengroup]") {
    const std::string tokenGroupName = "tokengroup";
    const model::TokenGroup* token_group{new model::TokenGroup{"test"}};
    const model::TokenGroup* token_group2 = new model::TokenGroup{tokenGroupName};

    REQUIRE(token_group != nullptr);
    REQUIRE(token_group2 != nullptr);
}

TEST_CASE("Test the getter of TokenGroup", "[tokengroup]") {
    const model::TokenGroup token_group{"test"};

    REQUIRE(token_group.getName() == "test");
    REQUIRE(token_group.getName() != "test1");
}

TEST_CASE("Test the setters of TokenGroup", "[tokengroup]") {
    model::TokenGroup token_group{"test"};
    REQUIRE(token_group.getName() == "test");

    token_group.setName("test2");
    REQUIRE(token_group.getName() == "test2");
}

TEST_CASE("Test adding and removing tokens of TokenGroup", "[tokengroup]") {
    model::TokenGroup token_group{"test"};
    const model::Token token1{"token1"};
    const model::Token token2{"token2"};
    token_group.addToken(token1);
    token_group.addToken(token2);
    REQUIRE(token_group.getTokens() == std::vector<model::Token>{token1, token2});

    token_group.removeToken(token2);
    REQUIRE(token_group.getTokens() == std::vector<model::Token>{token1});

    token_group.removeToken(token1);
    REQUIRE(token_group.getTokens().empty());
}

TEST_CASE("Test operator==", "[tokengroup]") {
    model::TokenGroup token_group1{"test1"};
    model::TokenGroup token_group2{"test2"};
    model::TokenGroup token_group3{"test3"};
    model::TokenGroup token_group4{"test1"};

    model::Token token1{"value1"};
    model::Token token2{"value2"};
    model::Token token3{"value3"};

    token_group1.addToken(token1);
    token_group1.addToken(token2);

    token_group2.addToken(token1);
    token_group2.addToken(token2);

    token_group3.addToken(token3);

    token_group4.addToken(token1);
    token_group4.addToken(token2);

    REQUIRE(token_group1 == token_group4);
    REQUIRE(token_group1 != token_group2);
    REQUIRE(token_group1 != token_group3);
    REQUIRE(token_group2 != token_group3);
}