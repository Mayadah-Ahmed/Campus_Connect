#ifndef IPOSTREPOSITORY_H
#define IPOSTREPOSITORY_H
#include "../models/Post.h"
#include <vector>
#include <memory>

namespace CampusConnect {
    namespace Repository {
        class IPostRepository {
        public:
            virtual ~IPostRepository() {}
            virtual void savePost(std::shared_ptr<Models::Post> post) = 0;
            virtual std::vector<std::shared_ptr<Models::Post>> findAll() = 0;
        };
    }
}
#endif