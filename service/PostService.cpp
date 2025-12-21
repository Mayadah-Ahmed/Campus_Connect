#include "PostService.h"

namespace CampusConnect::Service {

    void PostService::createPost(const std::string& content,
        const std::string& author) {
        posts.push_back(
            std::make_shared<Models::Post>(content, author)
        );
    }

    const std::vector<std::shared_ptr<Models::Post>>&
        PostService::getAllPosts() const {
        return posts;
    }

}
