#ifndef USER_H
#define USER_H
#include <string>


class User {
private:
    int id;
    std::string name;
    std::string email;
    std::string studentId;
    std::string password;

public:
    User(int id, std::string name, std::string email, std::string studentId, std::string password);
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getStudentId() const;
    std::string getPassword() const;
};
#endif