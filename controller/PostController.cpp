#include "PostController.h"
#include "../View/UIUtils.h"
#include <iostream>

namespace CampusConnect {
    namespace Controller {
        PostController::PostController(Service::PostService& ps) : postService(ps) {}

        void PostController::handleCreatePost(std::string currentUser) {
            std::string content;
            std::cout << "\033[36m" << "Write your post below:\n> ";
            std::getline(std::cin, content);

            postService.createPost(content, currentUser);
            std::cout << "\033[32m" << "\n Post published successfully!\n" << "\033[0m";
        }

        void PostController::handleShowFeed() {
            auto posts = postService.getFeed();
            if (posts.empty()) {
                std::cout << "No posts available yet.\n";
            }
            else {
                for (auto& p : posts) {
                    std::cout << "@" << p->getAuthorName() << ": " << p->getContent() << "\n";
                }
            }
        }
    }
}