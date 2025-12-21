#include "InMemoryUserRepository.h"

namespace CampusConnect::Repository {

    void InMemoryUserRepository::addUser(std::shared_ptr<Models::User> user) {
        users.push_back(user);
    }

    std::shared_ptr<Models::User>
        InMemoryUserRepository::findByEmail(const std::string& email) {
        for (auto& user : users) {
            if (user->getEmail() == email)
                return user;
        }
        return nullptr;
    }

}
