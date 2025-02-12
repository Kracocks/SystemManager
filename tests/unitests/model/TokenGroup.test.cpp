//
// Created by kracocks on 15/01/25.
//

#include <catch2/catch_all.hpp>
#include <memory>

#include "TokenGroup.h"
#include "Utils.h"

TEST_CASE("Test the constructors of TokenGroup", "[tokengroup]") {
    const std::string tokenGroupName {"tokengroup"};
    const model::TokenGroup* token_group {new model::TokenGroup{0, 0, "test"}};
    const model::TokenGroup* token_group2 {new model::TokenGroup{1,  0, tokenGroupName}};

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
    model::TokenGroup token_group{0, 0, "test"};
    REQUIRE(token_group.name == "test");

    token_group.name = "test2";
    REQUIRE(token_group.name == "test2");
}

TEST_CASE("Test adding and removing tokens of TokenGroup", "[tokengroup]") {
    model::TokenGroup token_group{0, 0, "test"};
	token_group.tokens[0] = "test1";
	token_group.tokens[1] = "test2";

    REQUIRE(token_group.tokens == std::unordered_map<int, std::string>{{0, "test1"},
																				{1, "test2"}});

	token_group.tokens.erase(1);
    REQUIRE(token_group.tokens == std::unordered_map<int, std::string>{{0, "test1"}});

	token_group.tokens.erase(0);
    REQUIRE(token_group.tokens.empty());
}