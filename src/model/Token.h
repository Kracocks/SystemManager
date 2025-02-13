//
// Created by kracocks on 12/01/25.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>

#include "TokenGroup.h"

namespace model {
	struct Token {
		int id;
		int tgroup_id;
		std::string value;

		void display() const;

		bool operator==(const Token &other) const;
	};
} // model

#endif //TOKEN_H
