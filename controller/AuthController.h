#pragma once
#include "../service/AuthService.h"
#include <memory>

namespace CampusConnect::Controller {

    class AuthController {
    private:
        Service::AuthService& authService;

    public:
        AuthController(Service::AuthService& service);

        std::shared_ptr<Models::User> login();
        void registerUser();
    };

}
