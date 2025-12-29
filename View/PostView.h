#ifndef POSTVIEW_H
#define POSTVIEW_H
#include "../models/Post.h"
#include <vector>

class PostView {
public:
    void promptForNewPost(std::string& content);
    void displayAllPosts(const std::vector<Post>& posts);
    void showMessage(std::string msg);
};
#endif