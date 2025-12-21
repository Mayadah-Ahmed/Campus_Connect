#include <iostream>
#include <memory>

#include "repository/InMemoryUserRepository.h"
#include "service/AuthService.h"
#include "service/PostService.h"
#include "controller/AuthController.h"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"



using namespace std;
using namespace CampusConnect;


void showHeader() {
    cout << CYAN << BOLD;
    cout << "==============================================\n";
    cout << "           CAMPUS CONNECT v1.0\n";
    cout << "       Student Community Platform\n";
    cout << "==============================================\n\n";
    cout << RESET;

}

void showAbout() {
    cout << CYAN << BOLD;
    cout << "\n========== ABOUT CAMPUS CONNECT ==========\n";
    cout << "Campus Connect is a student community platform\n";
    cout << "designed to help university students:\n\n";
    cout << "- Connect with peers\n";
    cout << "- Share posts and ideas\n";
    cout << "- Build a collaborative campus environment\n\n";
    cout << "This is a console-based demo version\n";
    cout << "implemented as part of Phase 3.\n";
    cout << "==========================================\n";
    cout << RESET;
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
            cout << CYAN <<"=== MAIN MENU (Not Logged In) ===\n";
            cout << CYAN << "1. Register New Account\n";
            cout << CYAN << "2. Login to Existing Account\n";
            cout << CYAN <<"3. About This Platform\n";
            cout << CYAN<< "0. Exit Program\n";
            cout << CYAN<< "Enter choice: " ;

            cin >> choice;
            cin.ignore();

            try {
                if (choice == 1) {
                    showHeader();
                    cout << CYAN <<"=== REGISTER ===\n\n";
                    authController.registerUser();
                }
                else if (choice == 2) {
                    showHeader();
                    cout << CYAN<< "=== LOGIN ===\n\n";
                    currentUser = authController.login();
                }
                else if (choice == 3) {
                    showHeader();
                    showAbout();
                }
                else if (choice == 0) {
                    cout << GREEN<< "\nThank you for using Campus Connect!\n";
                    break;
                }
                else {
                    cout << RED << "Invalid choice\n";
                }
            }
            catch (exception& e) {
                cout << "\n " << e.what() << "\n";
            }

            pauseScreen();
        }

        
        else {
            
            cout << CYAN <<BOLD<<" Welcome, " << currentUser->getName() << "!\n";
            cout << CYAN << BOLD << "==============================================\n\n";

            cout << CYAN <<"=== POST MANAGEMENT ===\n";
            cout << CYAN << "1. Create New Post\n";
            cout << CYAN << "2. View All Posts\n";
            cout << CYAN << "3. Logout\n";
            cout << CYAN << "0. Exit Program\n";
            cout << CYAN << "Enter choice: ";

            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                showHeader();
                cout << CYAN <<"=== CREATE NEW POST ===\n\n";
                string content;
                cout << CYAN <<"Write your post below:\n> ";
                getline(cin, content);

                postService.createPost(content, currentUser->getName());
                cout << CYAN<<"\n Post published successfully!\n";
                pauseScreen();
            }
            else if (choice == 2) {
                showHeader();
                cout << CYAN<<"========== FEED ==========\n\n";

                auto posts = postService.getAllPosts();
                if (posts.empty()) {
                    cout <<RED<< "No posts available yet.\n";
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
                cout <<GREEN<< "\nThank you for using Campus Connect!\n";
                break;
            }
            else {
                cout <<RED<< " Invalid choice.\n";
                pauseScreen();
            }
        }
    }

    return 0;
}
