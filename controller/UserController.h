#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include "../service/AuthService.h"
#include "../View/UserView.h"
#include <memory>

namespace CampusConnect {
    namespace Controller {
        class UserController {
        private:
            Service::AuthService& authService;
            View::UserView& view;
        public:
            UserController(Service::AuthService& as, View::UserView& uv);
            void handleRegister();
            std::shared_ptr<Models::User> handleLogin();
            void displayAbout();
        };
    }
}
#endif