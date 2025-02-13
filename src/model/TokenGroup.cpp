//
// Created by kracocks on 12/01/25.
//

#include <iostream>
#include <ostream>

#include "TokenGroup.h"

namespace model {
    void TokenGroup::display() const {
	    std::cout << name << "\n";
		for (const auto &[_, value] : tokens) {
			std::cout << value << "\n";
		}
    	std::cout << "\n";
    }
} // model