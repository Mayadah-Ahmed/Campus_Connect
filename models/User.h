#ifndef USER_H
#define USER_H
#include <string>

namespace CampusConnect {
    namespace Models {
        class User {
        private:
            int id;
            std::string name, email, studentId, password;
        public:
            User(int id, std::string n, std::string e, std::string sid, std::string p);
            std::string getName() const;
            std::string getEmail() const;
            std::string getPassword() const;
        };
    }
}
#endif