#include <iostream>

#include "Identifiant.h"

int main() {
    model::Identifiant ident("model", "test");
    std::cout << ident.getEmail();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
