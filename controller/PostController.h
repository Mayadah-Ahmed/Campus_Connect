#ifndef POSTCONTROLLER_H
#define POSTCONTROLLER_H
#include "../service/PostService.h"
#include <memory>

namespace CampusConnect {
    namespace Controller {
        class PostController {
        private:
            Service::PostService& postService;
        public:
            PostController(Service::PostService& ps);
            void handleCreatePost(std::string currentUser);
            void handleShowFeed();
        };
    }
}
#endif