#ifndef INMEMORYPOSTREPOSITORY_H
#define INMEMORYPOSTREPOSITORY_H
#include "IPostRepository.h"

class InMemoryPostRepository : public IPostRepository {
private:
    std::vector<Post> posts;
public:
    void savePost(Post post) override;
    std::vector<Post> findAll() override;
};
#endif