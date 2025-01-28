//
// Created by kracocks on 11/01/25.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <string>
#include <vector>

#include "Identifiant.h"
#include "TokenGroup.h"

namespace model {
	template <typename Int, typename Str, typename Ser, typename Bool>
	requires std::same_as<Int, int> && std::same_as<Str, std::string> && std::same_as<Ser, Service> && std::same_as<Bool, bool>
	class Identifiant;
	struct TokenGroup;

	struct Service {
	    int id;
	    std::string name;
	    std::vector<Identifiant<>> identifiants;
		std::vector<TokenGroup> tokenGroups;

		void display() const;
	};
} // model

#endif //SERVICE_H
