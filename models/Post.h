#pragma once
#include <string>

namespace CampusConnect::Models {

    class Post {
    private:
        std::string content;
        std::string authorName;

    public:
        Post(const std::string& content,
            const std::string& authorName);

        std::string getContent() const;
        std::string getAuthorName() const;
    };

}
