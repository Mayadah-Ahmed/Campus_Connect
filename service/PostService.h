#ifndef POSTSERVICE_H
#define POSTSERVICE_H
#include "../repository/IPostRepository.h"
#include <memory>

namespace CampusConnect {
    namespace Service {
        class PostService {
        private:
            std::shared_ptr<Repository::IPostRepository> postRepo;
        public:
            PostService(std::shared_ptr<Repository::IPostRepository> repo);
            void createPost(std::string content, std::string author);
            std::vector<std::shared_ptr<Models::Post>> getFeed();
        };
    }
}
#endif