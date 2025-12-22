#include <iostream>
#include <cassert>
#include <memory>
#include "../service/PostService.h"

using namespace CampusConnect;

class FeedServiceTest {
private:
    std::shared_ptr<Service::PostService> postService;
    int testsRun = 0;
    int testsPassed = 0;

public:
    void setUp() {
        postService = std::make_shared<Service::PostService>();
    }

    void test_FeedDisplaysAllPosts() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Post 1", "Ahmed Ali");
            postService->createPost("Post 2", "Sara Mohamed");
            postService->createPost("Post 3", "Fatima Hassan");
            const auto& feed = postService->getAllPosts();
            assert(feed.size() == 3);
            std::cout << "✓ test_FeedDisplaysAllPosts PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedDisplaysAllPosts FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedIsEmptyWhenNoPosts() {
        setUp();
        testsRun++;
        try {
            const auto& feed = postService->getAllPosts();
            assert(feed.size() == 0);
            std::cout << "✓ test_FeedIsEmptyWhenNoPosts PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedIsEmptyWhenNoPosts FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedDisplaysPostsInCreationOrder() {
        setUp();
        testsRun++;
        try {
            postService->createPost("First post", "User1");
            postService->createPost("Second post", "User2");
            postService->createPost("Third post", "User3");
            const auto& feed = postService->getAllPosts();
            assert(feed[0]->getContent() == "First post");
            assert(feed[1]->getContent() == "Second post");
            assert(feed[2]->getContent() == "Third post");
            std::cout << "✓ test_FeedDisplaysPostsInCreationOrder PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedDisplaysPostsInCreationOrder FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedCanHandleLargeNumberOfPosts() {
        setUp();
        testsRun++;
        try {
            for (int i = 0; i < 100; i++) {
                std::string content = "Post number " + std::to_string(i);
                postService->createPost(content, "User" + std::to_string(i % 5));
            }
            const auto& feed = postService->getAllPosts();
            assert(feed.size() == 100);
            std::cout << "✓ test_FeedCanHandleLargeNumberOfPosts PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanHandleLargeNumberOfPosts FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedDisplaysPostsFromDifferentAuthors() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Ahmed's post", "Ahmed Ali");
            postService->createPost("Sara's post", "Sara Mohamed");
            postService->createPost("Fatima's post", "Fatima Hassan");
            const auto& feed = postService->getAllPosts();
            assert(feed[0]->getAuthorName() == "Ahmed Ali");
            assert(feed[1]->getAuthorName() == "Sara Mohamed");
            assert(feed[2]->getAuthorName() == "Fatima Hassan");
            std::cout << "✓ test_FeedDisplaysPostsFromDifferentAuthors PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedDisplaysPostsFromDifferentAuthors FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedPersistsPostsAfterMultipleRetrievals() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Post 1", "User1");
            postService->createPost("Post 2", "User2");
            const auto& feed1 = postService->getAllPosts();
            assert(feed1.size() == 2);
            const auto& feed2 = postService->getAllPosts();
            assert(feed2.size() == 2);
            assert(feed1[0]->getContent() == feed2[0]->getContent());
            assert(feed1[1]->getContent() == feed2[1]->getContent());
            std::cout << "✓ test_FeedPersistsPostsAfterMultipleRetrievals PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedPersistsPostsAfterMultipleRetrievals FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedContainsValidPostReferences() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Test Post 1", "Author1");
            postService->createPost("Test Post 2", "Author2");
            const auto& feed = postService->getAllPosts();
            for (const auto& post : feed) {
                assert(post != nullptr);
                assert(!post->getContent().empty());
                assert(!post->getAuthorName().empty());
            }
            std::cout << "✓ test_FeedContainsValidPostReferences PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedContainsValidPostReferences FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedUpdatesWhenNewPostsAdded() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Initial post", "User1");
            const auto& feed1 = postService->getAllPosts();
            assert(feed1.size() == 1);
            postService->createPost("Second post", "User2");
            postService->createPost("Third post", "User3");
            const auto& feed2 = postService->getAllPosts();
            assert(feed2.size() == 3);
            std::cout << "✓ test_FeedUpdatesWhenNewPostsAdded PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedUpdatesWhenNewPostsAdded FAILED: " << e.what() << std::endl;
        }
    }

    void runAllTests() {
        std::cout << "\n========== FeedService Tests ==========" << std::endl;
        test_FeedDisplaysAllPosts();
        test_FeedIsEmptyWhenNoPosts();
        test_FeedDisplaysPostsInCreationOrder();
        test_FeedCanHandleLargeNumberOfPosts();
        test_FeedDisplaysPostsFromDifferentAuthors();
        test_FeedPersistsPostsAfterMultipleRetrievals();
        test_FeedContainsValidPostReferences();
        test_FeedUpdatesWhenNewPostsAdded();
        std::cout << "\n========== Test Summary ==========" << std::endl;
        std::cout << "Total Tests: " << testsRun << std::endl;
        std::cout << "Passed: " << testsPassed << std::endl;
        std::cout << "Failed: " << (testsRun - testsPassed) << std::endl;
        std::cout << "==================================\n" << std::endl;
    }
};

