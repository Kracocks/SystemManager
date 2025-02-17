//
// Created by kracocks on 12/01/25.
//

#ifndef TOKENGROUP_H
#define TOKENGROUP_H
#include <string>
#include <vector>

#include "Token.h"
#include "TokenGroup.h"

namespace model {
	struct TokenGroup {
		int id;
		int login_id;
		std::string name;
		std::vector<Token> tokens;

		void display() const;
	};
} // model

#endif //TOKENGROUP_H
