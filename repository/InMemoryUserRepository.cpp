#include "InMemoryUserRepository.h"

void InMemoryUserRepository::saveUser(User user) {
    users.push_back(user);
}

User* InMemoryUserRepository::findByEmail(std::string email) {
    for (auto& user : users) {
        if (user.getEmail() == email) return &user;
    }
    return nullptr;
}