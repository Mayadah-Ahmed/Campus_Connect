#pragma once
#include <vector>
#include <memory>
#include "../models/Post.h"

namespace CampusConnect::Service {

    class PostService {
    private:
        std::vector<std::shared_ptr<Models::Post>> posts;

    public:
        void createPost(const std::string& content,
            const std::string& author);

        const std::vector<std::shared_ptr<Models::Post>>& getAllPosts() const;
    };

}
