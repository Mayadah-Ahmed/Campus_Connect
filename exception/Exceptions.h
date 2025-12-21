#pragma once
#include <stdexcept>

namespace CampusConnect::Exceptions {

    class UserAlreadyExistsException : public std::runtime_error {
    public:
        UserAlreadyExistsException()
            : std::runtime_error("User already exists") {}
    };

    class InvalidCredentialsException : public std::runtime_error {
    public:
        InvalidCredentialsException()
            : std::runtime_error("Invalid email or password") {}
    };

}
