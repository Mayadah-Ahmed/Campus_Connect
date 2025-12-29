#include "View/UIUtils.h"
#include "controller/UserController.h"
#include "controller/PostController.h"
#include "repository/InMemoryUserRepository.h"
#include "repository/InMemoryPostRepository.h"

using namespace CampusConnect;

int main() {

    auto userRepo = std::make_shared<Repository::InMemoryUserRepository>();
    auto postRepo = std::make_shared<Repository::InMemoryPostRepository>();

    Service::AuthService authService(userRepo);
    Service::PostService postService(postRepo);

    View::UserView userView;
    Controller::UserController userCtrl(authService, userView);
    Controller::PostController postCtrl(postService);

    std::shared_ptr<Models::User> currentUser = nullptr;
    int choice;

    while (true) {
        View::UIUtils::showHeader();
        if (!currentUser) {
            std::cout << CYAN << "1. Register\n2. Login\n3. About\n0. Exit\nChoice: ";
            std::cin >> choice; std::cin.ignore();
            if (choice == 1) userCtrl.handleRegister();
            else if (choice == 2) currentUser = userCtrl.handleLogin();
            else if (choice == 3) userView.showAbout();
            else if (choice == 0) break;
        }
        else {
            std::cout << GREEN << "Welcome, " << currentUser->getName() << "!\n" << RESET;
            std::cout << CYAN << "1. Create Post\n2. News Feed\n3. Logout\n0. Exit\nChoice: ";
            std::cin >> choice; std::cin.ignore();
            if (choice == 1) postCtrl.handleCreatePost(currentUser->getName());
            else if (choice == 2) postCtrl.handleShowFeed();
            else if (choice == 3) currentUser = nullptr;
            else if (choice == 0) break;
        }
        View::UIUtils::pauseScreen();
    }
    return 0;
}