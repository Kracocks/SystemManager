//
// Created by kracocks on 12/01/25.
//

#ifndef TOKENGROUP_H
#define TOKENGROUP_H
#include <string>
#include <vector>

#include "Identifiant.h"
#include "Service.h"
#include "Token.h"
#include "TokenGroup.h"

namespace model {
	struct Service;
	struct TokenGroup;
	struct Token;

	template <typename Int, typename Str, typename Ser, typename Bool, typename TGroup>
	requires std::same_as<Int, int> &&
			 std::same_as<Str, std::string> &&
			 std::same_as<Ser, Service> &&
			 std::same_as<Bool, bool> &&
			 std::same_as<TGroup, TokenGroup>
	class Identifiant;

	struct TokenGroup {
		int id;
		std::string name;
		Identifiant<int, std::string, Service, bool, TokenGroup> login;
		std::vector<Token> tokens;

		void display() const;
	};
} // model

#endif //TOKENGROUP_H
