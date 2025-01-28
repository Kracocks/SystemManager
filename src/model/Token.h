//
// Created by kracocks on 12/01/25.
//

#ifndef TOKEN_H
#define TOKEN_H
#include <string>

namespace model {
	struct Token {
		int id;
		std::string value;

		void display() const;
	};
} // model

#endif //TOKEN_H
