//
// Created by kracocks on 12/01/25.
//

#ifndef TOKENGROUP_H
#define TOKENGROUP_H
#include <string>
#include <unordered_map>

#include "Identifiant.h"
#include "Service.h"
#include "TokenGroup.h"

namespace model {
	struct Service;
	struct TokenGroup;

	template <typename Int, typename Str, typename Ser, typename Bool, typename TGroup>
	requires std::same_as<Int, int> &&
			 std::same_as<Str, std::string> &&
			 std::same_as<Ser, Service> &&
			 std::same_as<Bool, bool> &&
			 std::same_as<TGroup, TokenGroup>
	class Identifiant;

	struct TokenGroup {
		int id;
		int login_id;
		std::string name;
		std::unordered_map<int, std::string> tokens;

		void display() const;
	};
} // model

#endif //TOKENGROUP_H
