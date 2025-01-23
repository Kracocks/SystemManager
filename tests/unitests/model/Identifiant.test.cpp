//
// Created by kracocks on 13/01/25.
//

#include <catch2/catch_all.hpp>

#include <Identifiant.h>

TEST_CASE("Test the constructors of Identifiant", "[identifiant]") {
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

TEST_CASE("Test the getters of Identifiant", "[identifiant]") {
    const model::Identifiant ident{"test@email.com","1234"};

    REQUIRE(ident.getEmail() == "test@email.com");
    REQUIRE(ident.getPassword() == "1234");
}

TEST_CASE("Test the setters of Identifiant", "[identifiant]") {
    model::Identifiant ident{"test@email.com","1234"};

    ident.setEmail("test1@email.com");
    REQUIRE(ident.getEmail() == "test1@email.com");
    ident.setPassword("4321");
    REQUIRE(ident.getPassword() == "4321");

    const std::string email {"test2@email.com"};
    const std::string password {"12345678"};
    ident.setEmail(email);
    REQUIRE(ident.getEmail() == "test2@email.com");
    ident.setPassword(password);
    REQUIRE(ident.getPassword() == "12345678");
}

TEST_CASE("Test operator==", "[identifiant]") {
    model::Identifiant ident1{"test@email.com","1234"};
    model::Identifiant ident2{"test@email.com","1234"};
    model::Identifiant ident3{"test@email.com","12345678"};

    REQUIRE(ident1 == ident2);
    REQUIRE(ident1 != ident3);
    REQUIRE(ident2 != ident3);
}