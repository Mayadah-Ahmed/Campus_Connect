#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H

#include "../models/User.h"
#include <memory>
#include <vector>

namespace CampusConnect {
    namespace Repository {
        class IUserRepository {
        public:
            virtual ~IUserRepository() {}
            virtual void saveUser(std::shared_ptr<Models::User> user) = 0;
            virtual std::shared_ptr<Models::User> findByEmail(std::string email) = 0;
        };
    }
}
#endif