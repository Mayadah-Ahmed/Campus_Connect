#include "User.h"

namespace CampusConnect {
    namespace Models {
        User::User(int id, std::string n, std::string e, std::string sid, std::string p)
            : id(id), name(n), email(e), studentId(sid), password(p) {
        }

        std::string User::getName() const { return name; }
        std::string User::getEmail() const { return email; }
        std::string User::getPassword() const { return password; }
    }
}