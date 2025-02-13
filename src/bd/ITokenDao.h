//
// Created by kracocks on 16/01/25.
//

#ifndef TOKENDAO_H
#define TOKENDAO_H

#include <vector>
#include "IGenericDao.h"
#include "../model/Token.h"

namespace bd {
	class IITokenDao: public IGenericDAO<model::Token> {
	public:
		~IITokenDao() override;

		virtual std::vector<model::Token> findByValue(const std::string &value) = 0;
		virtual std::vector<model::Token> findByValue(std::string &&value) = 0;
	};

} // bd

#endif TOKENDAO_H