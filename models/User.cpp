#include "User.h"

User::User(int id, std::string name, std::string email, std::string studentId, std::string password)
    : id(id), name(name), email(email), studentId(studentId), password(password) {
}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
std::string User::getStudentId() const { return studentId; }
std::string User::getPassword() const { return password; }