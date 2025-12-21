#include <iostream>
#include <memory>

#include "repository/InMemoryUserRepository.h"
#include "service/AuthService.h"
#include "service/PostService.h"
#include "controller/AuthController.h"

using namespace std;
using namespace CampusConnect;


void showHeader() {
    cout << "==============================================\n";
    cout << "           CAMPUS CONNECT v1.0\n";
    cout << "       Student Community Platform\n";
    cout << "==============================================\n\n";
}

void showAbout() {
    cout << "\n========== ABOUT CAMPUS CONNECT ==========\n";
    cout << "Campus Connect is a student community platform\n";
    cout << "designed to help university students:\n\n";
    cout << "- Connect with peers\n";
    cout << "- Share posts and ideas\n";
    cout << "- Build a collaborative campus environment\n\n";
    cout << "This is a console-based demo version\n";
    cout << "implemented as part of Phase 3.\n";
    cout << "==========================================\n";
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

/* ================= MAIN ================= */

int main() {

    
    auto repo = make_shared<Repository::InMemoryUserRepository>();
    Service::AuthService authService(repo);
    Service::PostService postService;
    Controller::AuthController authController(authService);

    shared_ptr<Models::User> currentUser = nullptr;
    int choice;

    while (true) {
        showHeader();

        
        if (!currentUser) {
            cout << "=== MAIN MENU (Not Logged In) ===\n";
            cout << "1. Register New Account\n";
            cout << "2. Login to Existing Account\n";
            cout << "3. About This Platform\n";
            cout << "0. Exit Program\n";
            cout << "Enter choice: ";

            cin >> choice;
            cin.ignore();

            try {
                if (choice == 1) {
                    showHeader();
                    cout << "=== REGISTER ===\n\n";
                    authController.registerUser();
                }
                else if (choice == 2) {
                    showHeader();
                    cout << "=== LOGIN ===\n\n";
                    currentUser = authController.login();
                }
                else if (choice == 3) {
                    showHeader();
                    showAbout();
                }
                else if (choice == 0) {
                    cout << "\nThank you for using Campus Connect!\n";
                    break;
                }
                else {
                    cout << " Invalid choice.\n";
                }
            }
            catch (exception& e) {
                cout << "\n " << e.what() << "\n";
            }

            pauseScreen();
        }

        
        else {
            showHeader();
            cout << " Welcome, " << currentUser->getName() << "!\n";
            cout << "==============================================\n\n";

            cout << "=== POST MANAGEMENT ===\n";
            cout << "1. Create New Post\n";
            cout << "2. View All Posts\n";
            cout << "3. Logout\n";
            cout << "0. Exit Program\n";
            cout << "Enter choice: ";

            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                showHeader();
                cout << "=== CREATE NEW POST ===\n\n";
                string content;
                cout << "Write your post below:\n> ";
                getline(cin, content);

                postService.createPost(content, currentUser->getName());
                cout << "\n Post published successfully!\n";
                pauseScreen();
            }
            else if (choice == 2) {
                showHeader();
                cout << "========== FEED ==========\n\n";

                auto posts = postService.getAllPosts();
                if (posts.empty()) {
                    cout << "No posts available yet.\n";
                }
                else {
                    for (auto& p : posts) {
                        cout  << p->getAuthorName() << "\n";
                        cout  << p->getContent() << "\n";
                        cout << "------------------------------\n";
                    }
                }
                pauseScreen();
            }
            else if (choice == 3) {
                currentUser = nullptr;
            }
            else if (choice == 0) {
                cout << "\nThank you for using Campus Connect!\n";
                break;
            }
            else {
                cout << " Invalid choice.\n";
                pauseScreen();
            }
        }
    }

    return 0;
}
