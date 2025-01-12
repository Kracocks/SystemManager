//
// Created by kracocks on 13/01/25.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "model/Identifiant.h"

TEST_CASE("Test the constructors of Identifiant", "[model]") {
    // Check if every constructor works
    const std::string email {"test@email.com"};
    const std::string password {"1234"};

    // lvalue and lvalue
    const model::Identifiant* ident2 {new model::Identifiant(email, password)};
    // rvalue and rvalue
    const model::Identifiant* ident1 {new model::Identifiant("test", "1234")};
    // rvalue and lvalue
    const model::Identifiant* ident3 {new model::Identifiant("test", password)};
    // lvalue and rvalue
    const model::Identifiant* ident4 {new model::Identifiant(email, "1234")};

    REQUIRE(ident1 != nullptr);
    REQUIRE(ident2 != nullptr);
    REQUIRE(ident3 != nullptr);
    REQUIRE(ident4 != nullptr);
    delete ident1;
    delete ident2;
    delete ident3;
    delete ident4;
}