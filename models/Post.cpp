#include "Post.h"

Post::Post(int id, std::string content, std::string authorName, std::string timestamp)
    : id(id), content(content), authorName(authorName), timestamp(timestamp) {
}

int Post::getId() const { return id; }
std::string Post::getContent() const { return content; }
std::string Post::getAuthorName() const { return authorName; }
std::string Post::getTimestamp() const { return timestamp; }