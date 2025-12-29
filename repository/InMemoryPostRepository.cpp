#include "InMemoryPostRepository.h"

void InMemoryPostRepository::savePost(Post post) {
    posts.push_back(post);
}

std::vector<Post> InMemoryPostRepository::findAll() {
    return posts;
}