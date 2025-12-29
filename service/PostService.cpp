#include "PostService.h"
#include <algorithm>
#include <ctime>

namespace CampusConnect {
    namespace Service {
        PostService::PostService(std::shared_ptr<Repository::IPostRepository> repo) : postRepo(repo) {}

        void PostService::createPost(std::string content, std::string author) {
            std::time_t now = std::time(0);
            char dt_buf[26];
            ctime_s(dt_buf, sizeof(dt_buf), &now);
            std::string ts(dt_buf);
            if (!ts.empty() && ts.back() == '\n') ts.pop_back();

            auto newPost = std::make_shared<Models::Post>(0, content, author, ts);
            postRepo->savePost(newPost);
        }

        std::vector<std::shared_ptr<Models::Post>> PostService::getFeed() {
            auto allPosts = postRepo->findAll();
            std::reverse(allPosts.begin(), allPosts.end());
            return allPosts;
        }
    }
}