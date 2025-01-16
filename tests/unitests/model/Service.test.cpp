//
// Created by kracocks on 16/01/25.
//

#include <catch2/catch_all.hpp>

#include "Token.h"
#include "TokenGroup.h"
#include "Service.h"

TEST_CASE("Test the constructors of Service", "[service]") {
    const std::string serviceName = "service";
    const model::Service* service1{new model::Service{"test"}};
    const model::Service* service2{new model::Service{serviceName}};

    REQUIRE(service1 != nullptr);
    REQUIRE(service2 != nullptr);
}

TEST_CASE("Test the getter of Service", "[service]") {
    const model::Service service{"test"};

    REQUIRE(service.getName() == "test");
    REQUIRE(service.getName() != "test1");
}

TEST_CASE("Test the setters of Service", "[service]") {
    model::Service service{"test"};
    REQUIRE(service.getName() == "test");

    service.setName("test2");
    REQUIRE(service.getName() == "test2");
}

TEST_CASE("Test adding and removing token groups of Service", "[service]") {
    model::Service service{"test"};

    // test token groups
    model::TokenGroup token_group1{"test1"};
    const model::Token token1{"token1"};
    token_group1.addToken(token1);

    model::TokenGroup token_group2{"test2"};
    const model::Token token2{"token1"};
    token_group2.addToken(token1);

    service.addTokenGroup(token_group1);
    service.addTokenGroup(token_group2);

    REQUIRE(service.getTokenGroups() == std::vector<model::TokenGroup>({token_group1, token_group2}));

    service.removeTokenGroup(token_group2);

    REQUIRE(service.getTokenGroups() == std::vector<model::TokenGroup>({token_group1}));

    service.removeTokenGroup(token_group1);

    REQUIRE(service.getTokenGroups().empty());

    // test identifiants
    const model::Identifiant ident1{"test@email.com", "1234"};
    service.addIdentifiant(ident1);

    const model::Identifiant ident2{"test@email.com", "1234"};
    service.addIdentifiant(ident2);

    REQUIRE(service.getIdentifiants() == std::vector<model::Identifiant>({ident1, ident2}));

    service.removeIdentifiant(ident2);

    REQUIRE(service.getIdentifiants() == std::vector<model::Identifiant>({ident1}));

    service.removeIdentifiant(ident1);

    REQUIRE(service.getIdentifiants().empty());
}