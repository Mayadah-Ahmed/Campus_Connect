#ifndef POSTCONTROLLER_H
#define POSTCONTROLLER_H
#include "../service/PostService.h"
#include "../View/PostView.h"

class PostController {
private:
    PostService& postService;
    PostView& postView;
public:
    PostController(PostService& ps, PostView& pv);
    void handleCreatePost(std::string currentUser);
    void handleShowFeed();
};
#endif