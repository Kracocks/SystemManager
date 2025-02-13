//
// Created by kracocks on 16/01/25.
//

#include <catch2/catch_all.hpp>

#include "Service.h"
#include "TokenGroup.h"
#include "Utils.h"

TEST_CASE("Test the constructors of Service", "[service]") {
    const std::string serviceName = "service";
    const model::Service* service1{new model::Service{0, "test"}};
    const model::Service* service2{new model::Service{1, serviceName}};

    REQUIRE(service1 != nullptr);
    REQUIRE(service2 != nullptr);

	delete service1;
	delete service2;
}

TEST_CASE("Test the getter of Service", "[service]") {
    const model::Service service{0, "test"};

    REQUIRE(service.name == "test");
    REQUIRE(service.name != "test1");
}

TEST_CASE("Test the setters of Service", "[service]") {
    model::Service service{0, "test"};
    REQUIRE(service.name == "test");

    service.name = "test2";
    REQUIRE(service.name == "test2");
}

TEST_CASE("Test adding and removing identifiant and token groups of Service", "[service]") {
    model::Service service{0, "test"};

    // test identifiants
    const model::Identifiant<> ident1{0, "test@email.com", "1234", false};
	service.identifiants.push_back(ident1);

    const model::Identifiant<> ident2{1, "test@email.com", "1234", false};
	service.identifiants.push_back(ident2);
	REQUIRE(service.identifiants == std::vector<model::Identifiant<>>({ident1, ident2}));

	model::Utils::removeElement(service.identifiants, ident2);
    REQUIRE(service.identifiants == std::vector<model::Identifiant<>>({ident1}));

	model::Utils::removeElement(service.identifiants, ident1);
    REQUIRE(service.identifiants.empty());
}