#include "View/UIUtils.h"
#include "controller/UserController.h"
#include "controller/PostController.h"
#include "repository/InMemoryUserRepository.h"
#include "repository/InMemoryPostRepository.h"
#include "tests/AuthServiceTest.cpp"
#include "tests/PostServiceTest.cpp"
#include "tests/FeedServiceTest.cpp"

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
            std::cout << CYAN << "=== MAIN MENU (Not Logged In) ===\n";
            std::cout << CYAN << "1. Register\n";
            std::cout << CYAN << "2. Login\n";
            std::cout << CYAN << "3. About\n";
            std::cout << CYAN << "4. Run Tests\n";
            std::cout << CYAN << "0. Exit\n";
            std::cout << CYAN << "Choice: " << RESET;
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1) {
                userCtrl.handleRegister();
            }
            else if (choice == 2) {
                currentUser = userCtrl.handleLogin();
            }
            else if (choice == 3) {
                userView.showAbout();
            }
            else if (choice == 4) {
                std::cout << "\n\n==================== RUNNING ALL TESTS ===================\n\n" << std::endl;

                AuthServiceTest authTests;
                authTests.runAllTests();

                PostServiceTest postTests;
                postTests.runAllTests();

                FeedServiceTest feedTests;
                feedTests.runAllTests();

                std::cout << "\n==================== ALL TESTS COMPLETED ===================\n\n" << std::endl;
            }
            else if (choice == 0) {
                std::cout << GREEN << "\nThank you for using Campus Connect!\n" << RESET;
                break;
            }
            else {
                std::cout << RED << "Invalid choice! Please try again.\n" << RESET;
            }
        }
        else {
            std::cout << GREEN << BOLD << "Welcome, " << currentUser->getName() << "!\n" << RESET;
            std::cout << CYAN << "=== POST MANAGEMENT ===\n";
            std::cout << CYAN << "1. Create Post\n";
            std::cout << CYAN << "2. News Feed\n";
            std::cout << CYAN << "3. Logout\n";
            std::cout << CYAN << "0. Exit\n";
            std::cout << CYAN << "Choice: " << RESET;
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1) {
                postCtrl.handleCreatePost(currentUser->getName());
            }
            else if (choice == 2) {
                postCtrl.handleShowFeed();
            }
            else if (choice == 3) {
                currentUser = nullptr;
                std::cout << GREEN << "Logged out successfully!\n" << RESET;
            }
            else if (choice == 0) {
                std::cout << GREEN << "\nThank you for using Campus Connect!\n" << RESET;
                break;
            }
            else {
                std::cout << RED << "Invalid choice! Please try again.\n" << RESET;
            }
        }

        View::UIUtils::pauseScreen();
    }

    return 0;
}