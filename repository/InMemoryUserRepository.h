#ifndef INMEMORYUSERREPOSITORY_H
#define INMEMORYUSERREPOSITORY_H

#include "IUserRepository.h"

namespace CampusConnect {
    namespace Repository {
        class InMemoryUserRepository : public IUserRepository {
        private:
           
            std::vector<std::shared_ptr<Models::User>> users;
        public:
            void saveUser(std::shared_ptr<Models::User> user) override;
            std::shared_ptr<Models::User> findByEmail(std::string email) override;
        };
    }
}
#endif