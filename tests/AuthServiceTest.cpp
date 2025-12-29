#include <iostream>
#include <cassert>
#include <memory>
#include "../models/User.h"

using namespace CampusConnect;

class AuthServiceTest {
private:
    int testsRun = 0;
    int testsPassed = 0;

public:
    void test_UserCanBeCreatedWithValidData() {
        testsRun++;
        try {
            auto user = std::make_shared<Models::User>(1, "Ahmed Ali", "ahmed@uni.edu", "STU001", "SecurePass123");
            assert(user->getName() == "Ahmed Ali");
            assert(user->getEmail() == "ahmed@uni.edu");
            assert(user->getPassword() == "SecurePass123");
            std::cout << "✓ test_UserCanBeCreatedWithValidData PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCanBeCreatedWithValidData FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserEmailCanBeRetrieved() {
        testsRun++;
        try {
            auto user = std::make_shared<Models::User>(2, "Sara Mohamed", "sara@uni.edu", "STU002", "Pass456");
            assert(user->getEmail() == "sara@uni.edu");
            std::cout << "✓ test_UserEmailCanBeRetrieved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserEmailCanBeRetrieved FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserPasswordCanBeRetrieved() {
        testsRun++;
        try {
            auto user = std::make_shared<Models::User>(3, "Fatima Hassan", "fatima@uni.edu", "STU003", "Pass789");
            assert(user->getPassword() == "Pass789");
            std::cout << "✓ test_UserPasswordCanBeRetrieved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserPasswordCanBeRetrieved FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserNameCanBeRetrieved() {
        testsRun++;
        try {
            auto user = std::make_shared<Models::User>(4, "Ali Hassan", "ali@uni.edu", "STU004", "Pass000");
            assert(user->getName() == "Ali Hassan");
            std::cout << "✓ test_UserNameCanBeRetrieved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserNameCanBeRetrieved FAILED: " << e.what() << std::endl;
        }
    }

    void test_MultipleUsersCanBeCreated() {
        testsRun++;
        try {
            auto user1 = std::make_shared<Models::User>(5, "User One", "user1@uni.edu", "STU005", "Pass111");
            auto user2 = std::make_shared<Models::User>(6, "User Two", "user2@uni.edu", "STU006", "Pass222");
            auto user3 = std::make_shared<Models::User>(7, "User Three", "user3@uni.edu", "STU007", "Pass333");

            assert(user1->getName() != user2->getName());
            assert(user2->getEmail() != user3->getEmail());
            std::cout << "✓ test_MultipleUsersCanBeCreated PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_MultipleUsersCanBeCreated FAILED: " << e.what() << std::endl;
        }
    }

    void test_PasswordIsCaseSensitive() {
        testsRun++;
        try {
            auto user1 = std::make_shared<Models::User>(8, "Test User", "test@uni.edu", "STU008", "SecurePass123");
            auto user2 = std::make_shared<Models::User>(9, "Test User2", "test2@uni.edu", "STU009", "securepass123");

            assert(user1->getPassword() != user2->getPassword());
            std::cout << "✓ test_PasswordIsCaseSensitive PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PasswordIsCaseSensitive FAILED: " << e.what() << std::endl;
        }
    }

    void test_EmailFormatIsPreserved() {
        testsRun++;
        try {
            auto user = std::make_shared<Models::User>(10, "Email Test", "email.test@university.edu", "STU010", "Pass");
            assert(user->getEmail() == "email.test@university.edu");
            std::cout << "✓ test_EmailFormatIsPreserved PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_EmailFormatIsPreserved FAILED: " << e.what() << std::endl;
        }
    }

    void runAllTests() {
        std::cout << "\n========== AuthService Tests ==========" << std::endl;
        test_UserCanBeCreatedWithValidData();
        test_UserEmailCanBeRetrieved();
        test_UserPasswordCanBeRetrieved();
        test_UserNameCanBeRetrieved();
        test_MultipleUsersCanBeCreated();
        test_PasswordIsCaseSensitive();
        test_EmailFormatIsPreserved();
        std::cout << "\n========== Test Summary ==========" << std::endl;
        std::cout << "Total Tests: " << testsRun << std::endl;
        std::cout << "Passed: " << testsPassed << std::endl;
        std::cout << "Failed: " << (testsRun - testsPassed) << std::endl;
        std::cout << "==================================\n" << std::endl;
    }
};