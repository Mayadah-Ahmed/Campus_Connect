#include "AuthController.h"
#include <iostream>
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"


using namespace std;

namespace CampusConnect::Controller {

    AuthController::AuthController(Service::AuthService& service)
        : authService(service) {
    }

    void AuthController::registerUser() {
        string id, name, email, password;

        cout <<CYAN<< "Student ID: ";
        cin >> id;
        cin.ignore();

        cout << CYAN << "Name: ";
        getline(cin, name);

        cout << CYAN << "Email: ";
        getline(cin, email);

        cout << CYAN << "Password: ";
        getline(cin, password);

        authService.registerUser(id, name, email, password);
        cout << GREEN<< " Registered successfully\n";
    }

    shared_ptr<Models::User> AuthController::login() {
        string email, password;

        cout << CYAN << "Email: ";
        getline(cin, email);

        cout << CYAN << "Password: ";
        getline(cin, password);

        auto user = authService.login(email, password);
        cout <<GREEN<< "Login successful\n";
        return user;
    }

}
