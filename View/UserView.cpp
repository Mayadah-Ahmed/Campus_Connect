#include "UserView.h"
#include "UIUtils.h"

namespace CampusConnect {
    namespace View {
        void UserView::showAbout() {
            std::cout << CYAN << BOLD;
            std::cout << "\n========== ABOUT CAMPUS CONNECT ==========\n";
            std::cout << "Campus Connect is a student community platform\n";
            std::cout << "designed to help university students:\n\n";
            std::cout << "- Connect with peers\n";
            std::cout << "- Share posts and ideas\n";
            std::cout << "- Build a collaborative campus environment\n\n";
            std::cout << "This is a console-based demo version\n";
            std::cout << "implemented as part of Phase 3.\n";
            std::cout << "==========================================\n" << RESET;
        }

        void UserView::showMessage(std::string msg, bool isError) {
            if (isError) std::cout << RED << "[Error]: " << msg << RESET << std::endl;
            else std::cout << GREEN << "[Success]: " << msg << RESET << std::endl;
        }

        void UserView::getRegistrationInput(std::string& name, std::string& email, std::string& sid, std::string& pass) {
            std::cout << CYAN << "Enter Name: "; std::getline(std::cin, name);
            std::cout << "Enter Email: "; std::cin >> email;
            std::cout << "Enter Student ID: "; std::cin >> sid;
            std::cout << "Enter Password: "; std::cin >> pass;
            std::cin.ignore();
        }
    }
}