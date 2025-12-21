#pragma once
#include "IUserRepository.h"
#include <vector>

namespace CampusConnect::Repository {

    class InMemoryUserRepository : public IUserRepository {
    private:
        std::vector<std::shared_ptr<Models::User>> users;

    public:
        void addUser(std::shared_ptr<Models::User> user) override;
        std::shared_ptr<Models::User> findByEmail(const std::string& email) override;
    };

}
