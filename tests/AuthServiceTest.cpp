#include <iostream>
#include <cassert>
#include <memory>
#include "../service/AuthService.h"
#include "../repository/InMemoryUserRepository.h"
#include "../exception/Exceptions.h"

using namespace CampusConnect;

class AuthServiceTest {
private:
    std::shared_ptr<Repository::IUserRepository> userRepo;
    std::shared_ptr<Service::AuthService> authService;
    int testsRun = 0;
    int testsPassed = 0;

public:
    void setUp() {
        userRepo = std::make_shared<Repository::InMemoryUserRepository>();
        authService = std::make_shared<Service::AuthService>(userRepo);
    }

    void test_UserCanRegisterSuccessfully() {
        setUp();
        testsRun++;
        try {
            authService->registerUser("STU001", "Ahmed Ali", "ahmed@uni.edu", "SecurePass123");
            auto user = userRepo->findByEmail("ahmed@uni.edu");
            assert(user != nullptr);
            assert(user->getEmail() == "ahmed@uni.edu");
            assert(user->getName() == "Ahmed Ali");
            std::cout << "✓ test_UserCanRegisterSuccessfully PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCanRegisterSuccessfully FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserCannotRegisterWithDuplicateEmail() {
        setUp();
        testsRun++;
        try {
            authService->registerUser("STU001", "Ahmed Ali", "ahmed@uni.edu", "Pass123");
            bool exceptionThrown = false;
            try {
                authService->registerUser("STU002", "Sara Mohamed", "ahmed@uni.edu", "DiffPass456");
            }
            catch (const Exceptions::UserAlreadyExistsException&) {
                exceptionThrown = true;
            }
            assert(exceptionThrown);
            std::cout << "✓ test_UserCannotRegisterWithDuplicateEmail PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCannotRegisterWithDuplicateEmail FAILED: " << e.what() << std::endl;
        }
    }

    void test_MultipleUsersCanRegisterWithDifferentEmails() {
        setUp();
        testsRun++;
        try {
            authService->registerUser("STU001", "Ahmed Ali", "ahmed@uni.edu", "Pass123");
            authService->registerUser("STU002", "Sara Mohamed", "sara@uni.edu", "Pass456");
            authService->registerUser("STU003", "Fatima Hassan", "fatima@uni.edu", "Pass789");

            assert(userRepo->findByEmail("ahmed@uni.edu") != nullptr);
            assert(userRepo->findByEmail("sara@uni.edu") != nullptr);
            assert(userRepo->findByEmail("fatima@uni.edu") != nullptr);
            std::cout << "✓ test_MultipleUsersCanRegisterWithDifferentEmails PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_MultipleUsersCanRegisterWithDifferentEmails FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserCanLoginWithCorrectCredentials() {
        setUp();
        testsRun++;
        try {
            authService->registerUser("STU001", "Ahmed Ali", "ahmed@uni.edu", "SecurePass123");
            auto loginUser = authService->login("ahmed@uni.edu", "SecurePass123");
            assert(loginUser != nullptr);
            assert(loginUser->getEmail() == "ahmed@uni.edu");
            assert(loginUser->getName() == "Ahmed Ali");
            std::cout << "✓ test_UserCanLoginWithCorrectCredentials PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCanLoginWithCorrectCredentials FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserCannotLoginWithWrongPassword() {
        setUp();
        testsRun++;
        try {
            authService->registerUser("STU001", "Ahmed Ali", "ahmed@uni.edu", "SecurePass123");
            bool exceptionThrown = false;
            try {
                authService->login("ahmed@uni.edu", "WrongPassword");
            }
            catch (const Exceptions::InvalidCredentialsException&) {
                exceptionThrown = true;
            }
            assert(exceptionThrown);
            std::cout << "✓ test_UserCannotLoginWithWrongPassword PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCannotLoginWithWrongPassword FAILED: " << e.what() << std::endl;
        }
    }

    void test_UserCannotLoginWithNonExistentEmail() {
        setUp();
        testsRun++;
        try {
            bool exceptionThrown = false;
            try {
                authService->login("nonexistent@uni.edu", "SomePassword");
            }
            catch (const Exceptions::InvalidCredentialsException&) {
                exceptionThrown = true;
            }
            assert(exceptionThrown);
            std::cout << "✓ test_UserCannotLoginWithNonExistentEmail PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_UserCannotLoginWithNonExistentEmail FAILED: " << e.what() << std::endl;
        }
    }

    void test_PasswordIsCaseSensitive() {
        setUp();
        testsRun++;
        try {
            authService->registerUser("STU001", "Ahmed Ali", "ahmed@uni.edu", "SecurePass123");
            bool exceptionThrown = false;
            try {
                authService->login("ahmed@uni.edu", "securepass123");
            }
            catch (const Exceptions::InvalidCredentialsException&) {
                exceptionThrown = true;
            }
            assert(exceptionThrown);
            std::cout << "✓ test_PasswordIsCaseSensitive PASSED" << std::endl;
            testsPassed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ test_PasswordIsCaseSensitive FAILED: " << e.what() << std::endl;
        }
    }

    void runAllTests() {
        std::cout << "\n========== AuthService Tests ==========" << std::endl;
        test_UserCanRegisterSuccessfully();
        test_UserCannotRegisterWithDuplicateEmail();
        test_MultipleUsersCanRegisterWithDifferentEmails();
        test_UserCanLoginWithCorrectCredentials();
        test_UserCannotLoginWithWrongPassword();
        test_UserCannotLoginWithNonExistentEmail();
        test_PasswordIsCaseSensitive();
        std::cout << "\n========== Test Summary ==========" << std::endl;
        std::cout << "Total Tests: " << testsRun << std::endl;
        std::cout << "Passed: " << testsPassed << std::endl;
        std::cout << "Failed: " << (testsRun - testsPassed) << std::endl;
        std::cout << "==================================\n" << std::endl;
    }
};

