#include "repository/InMemoryUserRepository.h"
#include "service/AuthService.h"
#include "View/UserView.h"
#include "controller/UserController.h"
#include <iostream>

int main() {
    InMemoryUserRepository userRepo;
    AuthService authService(userRepo);
    UserView userView;
    UserController userController(authService, userView);

    int choice;
    while (true) {
        std::cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";
        std::cin >> choice;
        if (choice == 1) userController.handleRegister();
        else if (choice == 2) userController.handleLogin();
        else break;
    }
    return 0;
}