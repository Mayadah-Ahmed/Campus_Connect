#ifndef IPOSTREPOSITORY_H
#define IPOSTREPOSITORY_H
#include "../models/Post.h"
#include <vector>

class IPostRepository {
public:
    virtual ~IPostRepository() {}
    virtual void savePost(Post post) = 0;
    virtual std::vector<Post> findAll() = 0;
};
#endif