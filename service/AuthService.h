#pragma once
#include <memory>
#include "../repository/IUserRepository.h"
#include "../exception/Exceptions.h"

namespace CampusConnect::Service {

    class AuthService {
    private:
        std::shared_ptr<Repository::IUserRepository> userRepo;

    public:
        AuthService(std::shared_ptr<Repository::IUserRepository> repo);

        void registerUser(const std::string& id,
            const std::string& name,
            const std::string& email,
            const std::string& password);

        std::shared_ptr<Models::User> login(const std::string& email,
            const std::string& password);
    };

}
