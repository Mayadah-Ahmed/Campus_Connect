#include "AuthService.h"

AuthService::AuthService(IUserRepository& repo) : userRepo(repo) {}

bool AuthService::registerUser(User u) {
    if (userRepo.findByEmail(u.getEmail()) == nullptr) {
        userRepo.saveUser(u);
        return true;
    }
    return false;
}

bool AuthService::login(std::string email, std::string pass) {
    User* user = userRepo.findByEmail(email);
    return (user != nullptr && user->getPassword() == pass);
}