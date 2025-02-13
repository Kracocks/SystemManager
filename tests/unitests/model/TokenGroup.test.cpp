//
// Created by kracocks on 15/01/25.
//

#include <catch2/catch_all.hpp>
#include <memory>

#include "Token.h"
#include "TokenGroup.h"

#include "Utils.h"

TEST_CASE("Test the constructors of TokenGroup", "[tokengroup]") {
    const std::string tokenGroupName {"tokengroup"};
	model::Identifiant<> login {0, "test", "test", false};
    const model::TokenGroup* token_group {new model::TokenGroup{0, 0, tokenGroupName}};
    const model::TokenGroup* token_group2 {new model::TokenGroup{1, 0, "tokengroup"}};

    REQUIRE(token_group != nullptr);
    REQUIRE(token_group2 != nullptr);

	delete token_group;
	delete token_group2;
}

TEST_CASE("Test the getter of TokenGroup", "[tokengroup]") {
    const model::TokenGroup token_group{0, 0, "test"};

    REQUIRE(token_group.name == "test");
    REQUIRE(token_group.name != "test1");
}

TEST_CASE("Test the setters of TokenGroup", "[tokengroup]") {
	model::Identifiant<> login {0, "test", "test", false};
    model::TokenGroup token_group{0, 0, "test"};
    REQUIRE(token_group.name == "test");

    token_group.name = "test2";
    REQUIRE(token_group.name == "test2");
}

TEST_CASE("Test adding and removing tokens of TokenGroup", "[tokengroup]") {
	model::Identifiant<> login {0, "test", "test", false};
    model::TokenGroup token_group{0, 0, "test"};
    const model::Token token1{0, 0, "token1"};
    const model::Token token2{1, 0, "token2"};
	token_group.tokens.push_back(token1);
	token_group.tokens.push_back(token2);

    REQUIRE(token_group.tokens == std::vector<model::Token>{token1, token2});

	model::Utils::removeElement(token_group.tokens, token2);
    REQUIRE(token_group.tokens == std::vector<model::Token>{token1});

	model::Utils::removeElement(token_group.tokens, token1);
    REQUIRE(token_group.tokens.empty());
}