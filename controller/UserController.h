#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H
#include "../service/AuthService.h"
#include "../View/UserView.h"

class UserController {
private:
    AuthService& authService;
    UserView& view;
public:
    UserController(AuthService& as, UserView& uv);
    void handleRegister();
    void handleLogin();
};
#endif