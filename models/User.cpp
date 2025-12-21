#include "User.h"

namespace CampusConnect::Models {

    User::User(const std::string& studentId,
        const std::string& name,
        const std::string& email,
        const std::string& password)
        : studentId(studentId), name(name), email(email), password(password) {
    }

    std::string User::getStudentId() const { return studentId; }
    std::string User::getName() const { return name; }
    std::string User::getEmail() const { return email; }
    std::string User::getPassword() const { return password; }

}
