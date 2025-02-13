//
// Created by kracocks on 12/01/25.
//

#include <iostream>
#include <ostream>

#include "Token.h"
#include "TokenGroup.h"

namespace model {
    void TokenGroup::display() const {
	    std::cout << name << "\n";
		for (const Token &token: tokens) {
			std::cout << "\t";
			token.display();
		}
    	std::cout << "\n";
    }
} // model