//
// Created by kracocks on 12/01/25.
//

#include "Token.h"

#include <iostream>

namespace model {
    void Token::display() const {
	    std::cout << value << "\n";
    }

	bool Token::operator==(const Token &other) const {
	    return (id == other.id) && (value == other.value);
    }
} // model
