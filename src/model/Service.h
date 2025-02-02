//
// Created by kracocks on 11/01/25.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <vector>

#include "Identifiant.h"

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

	struct Service {
	    int id;
	    std::string name;
	    std::vector<Identifiant<int, std::string, Service, bool, TokenGroup>> identifiants;

		void display() const;
	};
} // model

#endif //SERVICE_H
