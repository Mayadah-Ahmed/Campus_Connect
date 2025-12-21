#include "Post.h"

namespace CampusConnect::Models {

    Post::Post(const std::string& content,
        const std::string& authorName)
        : content(content), authorName(authorName) {
    }

    std::string Post::getContent() const { return content; }
    std::string Post::getAuthorName() const { return authorName; }

}
