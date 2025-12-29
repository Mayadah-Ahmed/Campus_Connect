#include "PostController.h"

PostController::PostController(PostService& ps, PostView& pv) : postService(ps), postView(pv) {}

void PostController::handleCreatePost(std::string currentUser) {
    std::string content;
    postView.promptForNewPost(content);
    postService.createPost(content, currentUser);
    postView.showMessage("Post created successfully!");
}

void PostController::handleShowFeed() {
    postView.displayAllPosts(postService.getFeed());
}