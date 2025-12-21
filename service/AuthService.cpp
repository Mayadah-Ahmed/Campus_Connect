#include "AuthService.h"

namespace CampusConnect::Service {

    AuthService::AuthService(std::shared_ptr<Repository::IUserRepository> repo)
        : userRepo(repo) {
    }

    void AuthService::registerUser(const std::string& id,
        const std::string& name,
        const std::string& email,
        const std::string& password) {
        if (userRepo->findByEmail(email))
            throw Exceptions::UserAlreadyExistsException();

        userRepo->addUser(
            std::make_shared<Models::User>(id, name, email, password)
        );
    }

    std::shared_ptr<Models::User>
        AuthService::login(const std::string& email,
            const std::string& password) {
        auto user = userRepo->findByEmail(email);
        if (!user || user->getPassword() != password)
            throw Exceptions::InvalidCredentialsException();

        return user;
    }

}
