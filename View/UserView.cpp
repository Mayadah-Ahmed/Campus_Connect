#include "UserView.h"
#include <iostream>

void UserView::showMessage(std::string msg) {
    std::cout << "[System]: " << msg << std::endl;
}

void UserView::getRegistrationInput(std::string& name, std::string& email, std::string& sid, std::string& pass) {
    std::cout << "Name: "; std::cin >> name;
    std::cout << "Email: "; std::cin >> email;
    std::cout << "Student ID: "; std::cin >> sid;
    std::cout << "Password: "; std::cin >> pass;
}

void UserView::getLoginInput(std::string& email, std::string& pass) {
    std::cout << "Email: "; std::cin >> email;
    std::cout << "Password: "; std::cin >> pass;
}