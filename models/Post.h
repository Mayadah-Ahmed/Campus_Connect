#ifndef POST_H
#define POST_H
#include <string>

namespace CampusConnect {
    namespace Models {
        class Post {
        private:
            int id;
            std::string content;
            std::string authorName;
            std::string timestamp;

        public:
            Post(int id, std::string content, std::string authorName, std::string timestamp);
            int getId() const;
            std::string getContent() const;
            std::string getAuthorName() const;
            std::string getTimestamp() const;
        };
    }
}
#endif