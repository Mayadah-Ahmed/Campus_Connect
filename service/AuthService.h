#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "../repository/IUserRepository.h"
#include <memory>

namespace CampusConnect {
    namespace Service {
        class AuthService {
        private:
           
            std::shared_ptr<Repository::IUserRepository> userRepo;

        public:
           
            AuthService(std::shared_ptr<Repository::IUserRepository> repo);

           
            bool registerUser(std::shared_ptr<Models::User> user);

          
            std::shared_ptr<Models::User> login(std::string email, std::string password);
        };
    }
}
#endif