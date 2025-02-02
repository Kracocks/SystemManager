//
// Created by kracocks on 12/01/25.
//

#ifndef TOKENGROUP_H
#define TOKENGROUP_H
#include <string>
#include <vector>

#include "Service.h"
#include "Token.h"

namespace model {
	struct TokenGroup {
		int id;
		std::string name;
		Identifiant<> login;
		std::vector<Token> tokens;

		void display() const;
	};
} // model

#endif //TOKENGROUP_H
