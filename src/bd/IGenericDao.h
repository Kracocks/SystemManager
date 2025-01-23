//
// Created by kracocks on 22/01/25.
//

#ifndef GENERICDAO_H
#define GENERICDAO_H

#include <vector>

namespace bd {

    template<class C>
    class IGenericDAO {
    public:
        virtual ~IGenericDAO() = default;

        virtual std::vector<C> findAll() = 0;
        virtual void insert(const C& item) = 0;
        virtual void remove(const C& item) = 0;
    };

} // bd

#endif //GENERICDAO_H
