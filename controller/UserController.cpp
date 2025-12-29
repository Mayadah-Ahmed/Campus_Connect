#include "UserController.h"
#include "../View/UIUtils.h"

namespace CampusConnect {
    namespace Controller {
        UserController::UserController(Service::AuthService& as, View::UserView& uv)
            : authService(as), view(uv) {
        }

        void UserController::handleRegister() {
            std::string n, e, sid, p;
            view.getRegistrationInput(n, e, sid, p);
            auto newUser = std::make_shared<Models::User>(0, n, e, sid, p);
            if (authService.registerUser(newUser)) view.showMessage("Account created successfully!");
            else view.showMessage("Email already exists!", true);
        }

        std::shared_ptr<Models::User> UserController::handleLogin() {
            std::string e, p;
            std::cout << CYAN << "Email: "; std::cin >> e;
            std::cout << "Password: "; std::cin >> p;
            std::cin.ignore();
            auto user = authService.login(e, p);
            if (user) return user;
            view.showMessage("Invalid email or password!", true);
            return nullptr;
        }

        void UserController::displayAbout() { view.showAbout(); }
    }
}