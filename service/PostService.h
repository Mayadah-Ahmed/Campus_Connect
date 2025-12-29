#ifndef POSTSERVICE_H
#define POSTSERVICE_H
#include <vector>
#include <string>
#include "../repository/IPostRepository.h"

class PostService {
private:
    IPostRepository& postRepo;
public:
    PostService(IPostRepository& repo);
    void createPost(std::string content, std::string author);
    std::vector<Post> getFeed();
};
#endif