#pragma once
#include <string>

namespace CampusConnect::Models {

    class User {
    private:
        std::string studentId;
        std::string name;
        std::string email;
        std::string password;

    public:
        User(const std::string& studentId,
            const std::string& name,
            const std::string& email,
            const std::string& password);

        std::string getStudentId() const;
        std::string getName() const;
        std::string getEmail() const;
        std::string getPassword() const;
    };

}
