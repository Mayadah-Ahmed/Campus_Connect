#include "PostView.h"
#include "UIUtils.h"
#include <iostream>

namespace CampusConnect {
    namespace View {

        void PostView::displayFeed(const std::vector<std::shared_ptr<Models::Post>>& posts) {
            std::cout << CYAN << BOLD << "\n========== NEWS FEED ==========\n" << RESET;

            if (posts.empty()) {
                std::cout << RED << "No posts available yet. Be the first to post!\n" << RESET;
                return;
            }

            for (const auto& post : posts) {
                std::cout << BOLD << "@" << post->getAuthorName() << RESET
                    << CYAN << " (" << post->getTimestamp() << ")\n";
                std::cout << " " << post->getContent() << "\n";
                std::cout << CYAN << "------------------------------\n" << RESET;
            }
        }

        void PostView::promptForPost(std::string& content) {
            std::cout << CYAN << "Write your post (Press Enter to publish):\n> ";
           
            std::getline(std::cin, content);
        }

        void PostView::showMessage(std::string msg, bool isError) {
            if (isError) {
                std::cout << RED << "[!] " << msg << RESET << std::endl;
            }
            else {
                std::cout << GREEN << "[*] " << msg << RESET << std::endl;
            }
        }
    }
}