#ifndef INMEMORYPOSTREPOSITORY_H
#define INMEMORYPOSTREPOSITORY_H
#include "IPostRepository.h"

namespace CampusConnect {
    namespace Repository {
        class InMemoryPostRepository : public IPostRepository {
        private:
            std::vector<std::shared_ptr<Models::Post>> posts;
        public:
            void savePost(std::shared_ptr<Models::Post> post) override;
            std::vector<std::shared_ptr<Models::Post>> findAll() override;
        };
    }
}
#endif