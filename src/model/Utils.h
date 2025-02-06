//
// Created by kracocks on 02/02/25.
//

#ifndef UTILS_H
#define UTILS_H

#include "Utils.h"

#include <vector>

namespace model {
	struct Utils {
		template <typename T>
		static void removeElement(std::vector<T> &vec, const T &value) {
			vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
		}
		template <typename T>
		static bool contains(std::vector<T> &vec, const T &value) {
			return std::find(vec.begin(), vec.end(), value) != vec.end();
		}
	};
}

#endif //UTILS_H
