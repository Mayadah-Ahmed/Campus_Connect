#pragma once
#include <memory>
#include "../models/User.h"

namespace CampusConnect::Repository {

    class IUserRepository {
    public:
        virtual void addUser(std::shared_ptr<Models::User> user) = 0;
        virtual std::shared_ptr<Models::User> findByEmail(const std::string& email) = 0;
        virtual ~IUserRepository() = default;
    };

}
