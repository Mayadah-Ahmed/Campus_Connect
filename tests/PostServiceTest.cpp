#include <iostream>
#include <cassert>
#include <memory>
#include <vector>
#include "../models/Post.h"

using namespace CampusConnect;

class PostServiceTest {
private:
    int testsRun = 0;
    int testsPassed = 0;

public:
    void test_PostCanBeCreatedWithValidData() {
        testsRun++;
        try {
            auto post = std::make_shared<Models::Post>(1, "Hello everyone!", "Ahmed Ali", "2024-01-01 10:30:00");
            assert(post->getContent() == "Hello everyone!");
            assert(post->getAuthorName() == "Ahmed Ali");
            assert(post->getId() == 1);
            std::cout << "✓ test_PostCanBeCreatedWithValidData PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostCanBeCreatedWithValidData FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostContentCanBeRetrieved() {
        testsRun++;
        try {
            std::string content = "Check out this amazing campus event!";
            auto post = std::make_shared<Models::Post>(2, content, "Sara Mohamed", "2024-01-01 11:00:00");
            assert(post->getContent() == content);
            std::cout << "✓ test_PostContentCanBeRetrieved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostContentCanBeRetrieved FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostAuthorCanBeRetrieved() {
        testsRun++;
        try {
            auto post = std::make_shared<Models::Post>(3, "Test post", "Fatima Hassan", "2024-01-01 12:00:00");
            assert(post->getAuthorName() == "Fatima Hassan");
            std::cout << "✓ test_PostAuthorCanBeRetrieved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostAuthorCanBeRetrieved FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostTimestampCanBeRetrieved() {
        testsRun++;
        try {
            std::string timestamp = "2024-01-01 13:30:00";
            auto post = std::make_shared<Models::Post>(4, "Another post", "Ali Hassan", timestamp);
            assert(post->getTimestamp() == timestamp);
            std::cout << "✓ test_PostTimestampCanBeRetrieved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostTimestampCanBeRetrieved FAILED: " << e.what() << std::endl;
        }
    }

    void test_MultiplePostsCanBeCreated() {
        testsRun++;
        try {
            auto post1 = std::make_shared<Models::Post>(5, "First post", "User1", "2024-01-01 14:00:00");
            auto post2 = std::make_shared<Models::Post>(6, "Second post", "User2", "2024-01-01 15:00:00");
            auto post3 = std::make_shared<Models::Post>(7, "Third post", "User3", "2024-01-01 16:00:00");

            assert(post1->getId() != post2->getId());
            assert(post2->getContent() != post3->getContent());
            std::cout << "✓ test_MultiplePostsCanBeCreated PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_MultiplePostsCanBeCreated FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostWithLongContentCanBeCreated() {
        testsRun++;
        try {
            std::string longContent = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";
            auto post = std::make_shared<Models::Post>(8, longContent, "Test Author", "2024-01-01 17:00:00");
            assert(post->getContent() == longContent);
            std::cout << "✓ test_PostWithLongContentCanBeCreated PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostWithLongContentCanBeCreated FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostWithSpecialCharactersCanBeCreated() {
        testsRun++;
        try {
            std::string content = "Check this out! @everyone #StudyBuddy $100 (amazing!)";
            auto post = std::make_shared<Models::Post>(9, content, "Special User", "2024-01-01 18:00:00");
            assert(post->getContent() == content);
            std::cout << "✓ test_PostWithSpecialCharactersCanBeCreated PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostWithSpecialCharactersCanBeCreated FAILED: " << e.what() << std::endl;
        }
    }

    void test_PostIdIsUnique() {
        testsRun++;
        try {
            auto post1 = std::make_shared<Models::Post>(10, "Post 1", "Author1", "2024-01-01 19:00:00");
            auto post2 = std::make_shared<Models::Post>(11, "Post 2", "Author2", "2024-01-01 20:00:00");
            auto post3 = std::make_shared<Models::Post>(12, "Post 3", "Author3", "2024-01-01 21:00:00");

            assert(post1->getId() != post2->getId());
            assert(post2->getId() != post3->getId());
            assert(post1->getId() != post3->getId());
            std::cout << "✓ test_PostIdIsUnique PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PostIdIsUnique FAILED: " << e.what() << std::endl;
        }
    }

    void runAllTests() {
        std::cout << "\n========== PostService Tests ==========" << std::endl;
        test_PostCanBeCreatedWithValidData();
        test_PostContentCanBeRetrieved();
        test_PostAuthorCanBeRetrieved();
        test_PostTimestampCanBeRetrieved();
        test_MultiplePostsCanBeCreated();
        test_PostWithLongContentCanBeCreated();
        test_PostWithSpecialCharactersCanBeCreated();
        test_PostIdIsUnique();
        std::cout << "\n========== Test Summary ==========" << std::endl;
        std::cout << "Total Tests: " << testsRun << std::endl;
        std::cout << "Passed: " << testsPassed << std::endl;
        std::cout << "Failed: " << (testsRun - testsPassed) << std::endl;
        std::cout << "==================================\n" << std::endl;
    }
};