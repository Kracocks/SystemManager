//
// Created by kracocks on 11/01/25.
//

#include "Service.h"
#include "Identifiant.h"

#include <iostream>

namespace model {
	void Service::display() const {
    	std::cout << "Service " << name << ":\npasswords :\n";
        for (const Identifiant<> &login : identifiants) {
            login.display();
        }
        std::cout << "\ntokens :\n";
        for (const TokenGroup &tGroup : tokenGroups) {
            tGroup.display();
        }
        std::cout << "\n";
    }
} // model