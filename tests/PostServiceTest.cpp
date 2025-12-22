#include <iostream>
#include <cassert>
#include <memory>
#include "../service/PostService.h"

using namespace CampusConnect;

class PostServiceTest {
private:
    std::shared_ptr<Service::PostService> postService;
    int testsRun = 0;
    int testsPassed = 0;

public:
    void setUp() {
        postService = std::make_shared<Service::PostService>();
    }

    void test_UserCanCreatePostSuccessfully() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Hello everyone! This is my first post.", "Ahmed Ali");
            const auto& posts = postService->getAllPosts();
            assert(posts.size() == 1);
            assert(posts[0]->getContent() == "Hello everyone! This is my first post.");
            assert(posts[0]->getAuthorName() == "Ahmed Ali");
            std::cout << "✓ test_UserCanCreatePostSuccessfully PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCanCreatePostSuccessfully FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserCanCreateMultiplePosts() {
        setUp();
        testsRun++;
        try {
            postService->createPost("First post", "Ahmed Ali");
            postService->createPost("Second post", "Sara Mohamed");
            postService->createPost("Third post", "Ahmed Ali");
            const auto& posts = postService->getAllPosts();
            assert(posts.size() == 3);
            assert(posts[0]->getAuthorName() == "Ahmed Ali");
            assert(posts[1]->getAuthorName() == "Sara Mohamed");
            assert(posts[2]->getAuthorName() == "Ahmed Ali");
            std::cout << "✓ test_UserCanCreateMultiplePosts PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCanCreateMultiplePosts FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostContentIsStoredCorrectly() {
        setUp();
        testsRun++;
        try {
            std::string content = "Check out this amazing campus event happening tomorrow!";
            postService->createPost(content, "Fatima Hassan");
            const auto& posts = postService->getAllPosts();
            assert(posts[0]->getContent() == content);
            std::cout << "✓ test_PostContentIsStoredCorrectly PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostContentIsStoredCorrectly FAILED: " << e.what() << std::endl;
        }
    }

    void test_MultipleSameAuthorPostsStoredSeparately() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Post 1", "Ahmed Ali");
            postService->createPost("Post 2", "Ahmed Ali");
            postService->createPost("Post 3", "Ahmed Ali");
            const auto& posts = postService->getAllPosts();
            assert(posts.size() == 3);
            for (const auto& post : posts) {
                assert(post->getAuthorName() == "Ahmed Ali");
            }
            std::cout << "✓ test_MultipleSameAuthorPostsStoredSeparately PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_MultipleSameAuthorPostsStoredSeparately FAILED: " << e.what() << std::endl;
        }
    }

    void test_GetAllPostsReturnsInCreationOrder() {
        setUp();
        testsRun++;
        try {
            postService->createPost("First", "User1");
            postService->createPost("Second", "User2");
            postService->createPost("Third", "User3");
            const auto& posts = postService->getAllPosts();
            assert(posts[0]->getContent() == "First");
            assert(posts[1]->getContent() == "Second");
            assert(posts[2]->getContent() == "Third");
            std::cout << "✓ test_GetAllPostsReturnsInCreationOrder PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_GetAllPostsReturnsInCreationOrder FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostWithLongContentIsStoredCorrectly() {
        setUp();
        testsRun++;
        try {
            std::string longContent = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";
            postService->createPost(longContent, "Ahmed Ali");
            const auto& posts = postService->getAllPosts();
            assert(posts[0]->getContent() == longContent);
            std::cout << "✓ test_PostWithLongContentIsStoredCorrectly PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostWithLongContentIsStoredCorrectly FAILED: " << e.what() << std::endl;
        }
    }

    void test_EmptyPostListInitially() {
        setUp();
        testsRun++;
        try {
            const auto& posts = postService->getAllPosts();
            assert(posts.size() == 0);
            std::cout << "✓ test_EmptyPostListInitially PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_EmptyPostListInitially FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostReferencesAreValidAfterCreation() {
        setUp();
        testsRun++;
        try {
            postService->createPost("Test post", "Test Author");
            postService->createPost("Another post", "Another Author");
            const auto& posts = postService->getAllPosts();
            assert(posts.size() >= 2);
            assert(posts[0] != nullptr);
            assert(posts[1] != nullptr);
            assert(posts[0] != posts[1]);
            std::cout << "✓ test_PostReferencesAreValidAfterCreation PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostReferencesAreValidAfterCreation FAILED: " << e.what() << std::endl;
        }
    }

    void runAllTests() {
        std::cout << "\n========== PostService Tests ==========" << std::endl;
        test_UserCanCreatePostSuccessfully();
        test_UserCanCreateMultiplePosts();
        test_PostContentIsStoredCorrectly();
        test_MultipleSameAuthorPostsStoredSeparately();
        test_GetAllPostsReturnsInCreationOrder();
        test_PostWithLongContentIsStoredCorrectly();
        test_EmptyPostListInitially();
        test_PostReferencesAreValidAfterCreation();
        std::cout << "\n========== Test Summary ==========" << std::endl;
        std::cout << "Total Tests: " << testsRun << std::endl;
        std::cout << "Passed: " << testsPassed << std::endl;
        std::cout << "Failed: " << (testsRun - testsPassed) << std::endl;
        std::cout << "==================================\n" << std::endl;
    }
};

