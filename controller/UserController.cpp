#include "UserController.h"

UserController::UserController(AuthService& as, UserView& uv) : authService(as), view(uv) {}

void UserController::handleRegister() {
    std::string n, e, sid, p;
    view.getRegistrationInput(n, e, sid, p);
    User newUser(0, n, e, sid, p);
    if (authService.registerUser(newUser)) view.showMessage("Success!");
    else view.showMessage("Failed!");
}

void UserController::handleLogin() {
    std::string e, p;
    view.getLoginInput(e, p);
    if (authService.login(e, p)) view.showMessage("Welcome!");
    else view.showMessage("Invalid Credentials!");
}