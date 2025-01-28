//
// Created by kracocks on 12/01/25.
//

#include "TokenGroup.h"

#include <iostream>
#include <ostream>

namespace model {
    void TokenGroup::display() const {
	    std::cout << name;
		for (const Token &token: tokens) {
			std::cout << "\t";
			token.display();
		}
    	std::cout << "\n";
    }
} // model