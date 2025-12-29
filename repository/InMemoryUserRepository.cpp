#include "InMemoryUserRepository.h"

namespace CampusConnect {
    namespace Repository {
        void InMemoryUserRepository::saveUser(std::shared_ptr<Models::User> user) {
            users.push_back(user);
        }

        std::shared_ptr<Models::User> InMemoryUserRepository::findByEmail(std::string email) {
            for (const auto& user : users) {
                if (user->getEmail() == email) {
                    return user;
                }
            }
            return nullptr;
        }
    }
}