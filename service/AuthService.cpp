#include "AuthService.h"

namespace CampusConnect {
    namespace Service {

        AuthService::AuthService(std::shared_ptr<Repository::IUserRepository> repo)
            : userRepo(repo) {
        }

        bool AuthService::registerUser(std::shared_ptr<Models::User> user) {
            if (userRepo->findByEmail(user->getEmail()) != nullptr) {
                return false;
            }

       
            userRepo->saveUser(user);
            return true;
        }

        std::shared_ptr<Models::User> AuthService::login(std::string email, std::string password) {
       
            auto user = userRepo->findByEmail(email);

            if (user != nullptr && user->getPassword() == password) {
                return user;
            }

            return nullptr;
        }

    }
}