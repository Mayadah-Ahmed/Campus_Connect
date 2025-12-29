#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H
#include "../repository/IUserRepository.h"

class AuthService {
private:
    IUserRepository& userRepo;
public:
    AuthService(IUserRepository& repo);
    bool registerUser(User u);
    bool login(std::string email, std::string pass);
};
#endif