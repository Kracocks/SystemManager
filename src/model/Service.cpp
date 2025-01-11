//
// Created by kracocks on 11/01/25.
//

#include "Service.h"

namespace model {
    Service::Service(const std::string &name): m_name(name) {
    }

    Service::Service(std::string &&name): m_name(name) {
    }

    std::string Service::getName() const {
        return m_name;
    }

    void Service::setName(const std::string &name) {
        m_name = name;
    }

    void Service::setName(std::string &&name) {
        m_name = name;
    }
} // model