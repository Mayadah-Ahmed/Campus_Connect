#include "InMemoryPostRepository.h"

namespace CampusConnect {
    namespace Repository {
        void InMemoryPostRepository::savePost(std::shared_ptr<Models::Post> post) {
            posts.push_back(post);
        }

        std::vector<std::shared_ptr<Models::Post>> InMemoryPostRepository::findAll() {
            return posts;
        }
    }
}