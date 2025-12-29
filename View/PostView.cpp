#include "PostView.h"
#include <iostream>

void PostView::promptForNewPost(std::string& content) {
    std::cout << "Write your post: ";
    std::cin.ignore();
    std::getline(std::cin, content);
}

void PostView::displayAllPosts(const std::vector<Post>& posts) {
    std::cout << "\n--- News Feed ---\n";
    for (const auto& post : posts) {
        std::cout << "From: " << post.getAuthorName() << " (" << post.getTimestamp() << ")" << std::endl;
        std::cout << post.getContent() << std::endl;
        std::cout << "-----------------" << std::endl;
    }
}

void PostView::showMessage(std::string msg) {
    std::cout << "[System]: " << msg << std::endl;
}