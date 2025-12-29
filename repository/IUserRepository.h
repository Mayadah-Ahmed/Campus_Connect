#ifndef IUSERREPOSITORY_H
#define IUSERREPOSITORY_H
#include "../models/User.h"

class IUserRepository {
public:
    virtual ~IUserRepository() {}
    virtual void saveUser(User user) = 0;
    virtual User* findByEmail(std::string email) = 0;
};
#endif