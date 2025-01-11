//
// Created by kracocks on 11/01/25.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <string>

namespace model {

    class Service {
        std::string m_name;
    public:
        Service() = delete;
        explicit Service(const std::string &name);
        explicit Service(std::string &&name);

        [[nodiscard]] std::string getName() const;
        void setName(const std::string &name);
        void setName(std::string &&name);
    };

} // model

#endif //SERVICE_H
