#include <iostream>
#include <cassert>
#include <memory>
#include <vector>
#include "../models/Post.h"

using namespace CampusConnect;

class FeedServiceTest {
private:
    int testsRun = 0;
    int testsPassed = 0;

public:
    void test_FeedCanStoreMultiplePosts() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            auto post1 = std::make_shared<Models::Post>(1, "Post 1", "Author1", "2024-01-01 10:00:00");
            auto post2 = std::make_shared<Models::Post>(2, "Post 2", "Author2", "2024-01-01 11:00:00");
            auto post3 = std::make_shared<Models::Post>(3, "Post 3", "Author3", "2024-01-01 12:00:00");

            feed.push_back(post1);
            feed.push_back(post2);
            feed.push_back(post3);

            assert(feed.size() == 3);
            std::cout << "✓ test_FeedCanStoreMultiplePosts PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanStoreMultiplePosts FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedCanBeEmpty() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            assert(feed.size() == 0);
            std::cout << "✓ test_FeedCanBeEmpty PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanBeEmpty FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedCanRetrievePostsInOrder() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            auto post1 = std::make_shared<Models::Post>(10, "First", "Author1", "2024-01-01 10:00:00");
            auto post2 = std::make_shared<Models::Post>(11, "Second", "Author2", "2024-01-01 11:00:00");
            auto post3 = std::make_shared<Models::Post>(12, "Third", "Author3", "2024-01-01 12:00:00");

            feed.push_back(post1);
            feed.push_back(post2);
            feed.push_back(post3);

            assert(feed[0]->getContent() == "First");
            assert(feed[1]->getContent() == "Second");
            assert(feed[2]->getContent() == "Third");
            std::cout << "✓ test_FeedCanRetrievePostsInOrder PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanRetrievePostsInOrder FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedCanHandleLargeNumberOfPosts() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            for (int i = 0; i < 100; i++) {
                auto post = std::make_shared<Models::Post>(i, "Post " + std::to_string(i),
                    "Author" + std::to_string(i % 5),
                    "2024-01-01 12:00:00");
                feed.push_back(post);
            }
            assert(feed.size() == 100);
            std::cout << "✓ test_FeedCanHandleLargeNumberOfPosts PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanHandleLargeNumberOfPosts FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedCanFilterByAuthor() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            auto post1 = std::make_shared<Models::Post>(20, "Ahmed's post 1", "Ahmed Ali", "2024-01-01 10:00:00");
            auto post2 = std::make_shared<Models::Post>(21, "Sara's post", "Sara Mohamed", "2024-01-01 11:00:00");
            auto post3 = std::make_shared<Models::Post>(22, "Ahmed's post 2", "Ahmed Ali", "2024-01-01 12:00:00");

            feed.push_back(post1);
            feed.push_back(post2);
            feed.push_back(post3);

            int ahmedPostCount = 0;
            for (const auto& post : feed) {
                if (post->getAuthorName() == "Ahmed Ali") {
                    ahmedPostCount++;
                }
            }
            assert(ahmedPostCount == 2);
            std::cout << "✓ test_FeedCanFilterByAuthor PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanFilterByAuthor FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedCanCheckPostExistence() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            auto post1 = std::make_shared<Models::Post>(30, "Test Post", "Author", "2024-01-01 10:00:00");
            feed.push_back(post1);

            bool postFound = false;
            for (const auto& post : feed) {
                if (post->getId() == 30) {
                    postFound = true;
                    break;
                }
            }
            assert(postFound == true);
            std::cout << "✓ test_FeedCanCheckPostExistence PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedCanCheckPostExistence FAILED: " << e.what() << std::endl;
        }
    }

    void test_FeedPostsHaveValidReferences() {
        testsRun++;
        try {
            std::vector<std::shared_ptr<Models::Post>> feed;
            auto post1 = std::make_shared<Models::Post>(40, "Valid Post 1", "Author1", "2024-01-01 10:00:00");
            auto post2 = std::make_shared<Models::Post>(41, "Valid Post 2", "Author2", "2024-01-01 11:00:00");

            feed.push_back(post1);
            feed.push_back(post2);

            for (const auto& post : feed) {
                assert(post != nullptr);
                assert(!post->getContent().empty());
                assert(!post->getAuthorName().empty());
            }
            std::cout << "✓ test_FeedPostsHaveValidReferences PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_FeedPostsHaveValidReferences FAILED: " << e.what() << std::endl;
        }
    }

    void runAllTests() {
        std::cout << "\n========== FeedService Tests ==========" << std::endl;
        test_FeedCanBeEmpty();
        test_FeedCanStoreMultiplePosts();
        test_FeedCanRetrievePostsInOrder();
        test_FeedCanHandleLargeNumberOfPosts();
        test_FeedCanFilterByAuthor();
        test_FeedCanCheckPostExistence();
        test_FeedPostsHaveValidReferences();
        std::cout << "\n========== Test Summary ==========" << std::endl;
        std::cout << "Total Tests: " << testsRun << std::endl;
        std::cout << "Passed: " << testsPassed << std::endl;
        std::cout << "Failed: " << (testsRun - testsPassed) << std::endl;
        std::cout << "==================================\n" << std::endl;
    }
};