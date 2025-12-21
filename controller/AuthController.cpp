#include "AuthController.h"
#include <iostream>

using namespace std;

namespace CampusConnect::Controller {

    AuthController::AuthController(Service::AuthService& service)
        : authService(service) {
    }

    void AuthController::registerUser() {
        string id, name, email, password;

        cout << "Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);

        cout << "Email: ";
        getline(cin, email);

        cout << "Password: ";
        getline(cin, password);

        authService.registerUser(id, name, email, password);
        cout << "✅ Registered successfully\n";
    }

    shared_ptr<Models::User> AuthController::login() {
        string email, password;

        cout << "Email: ";
        getline(cin, email);

        cout << "Password: ";
        getline(cin, password);

        auto user = authService.login(email, password);
        cout << "✅ Login successful\n";
        return user;
    }

}
