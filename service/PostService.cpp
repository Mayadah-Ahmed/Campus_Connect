#include "PostService.h"
#include <algorithm>
#include <ctime>
#include <vector>

PostService::PostService(IPostRepository& repo) : postRepo(repo) {}

void PostService::createPost(std::string content, std::string author) {
    std::time_t now = std::time(0);
    std::string dt = std::ctime(&now);

    // إزالة حرف السطر الجديد الذي تطلقه ctime تلقائياً
    if (!dt.empty() && dt[dt.length() - 1] == '\n') {
        dt.erase(dt.length() - 1);
    }

    Post newPost(0, content, author, dt);
    postRepo.savePost(newPost);
}

std::vector<Post> PostService::getFeed() {
    std::vector<Post> allPosts = postRepo.findAll();

    // تطبيق الترتيب الزمني العكسي (الأحدث أولاً) كما هو مطلوب في المواصفات
    std::reverse(allPosts.begin(), allPosts.end());

    return allPosts;
}