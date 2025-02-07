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
			auto it = std::find(vec.begin(), vec.end(), value);
			if (it != vec.end()) {
				vec.erase(it);
			}
		}
		template <typename T>
		static bool contains(std::vector<T> &vec, const T &value) {
			return std::find(vec.begin(), vec.end(), value) != vec.end();
		}
	};
}

#endif //UTILS_H
