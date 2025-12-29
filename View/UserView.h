#ifndef USERVIEW_H
#define USERVIEW_H
#include <string>

class UserView {
public:
    void showMessage(std::string msg);
    void getRegistrationInput(std::string& name, std::string& email, std::string& sid, std::string& pass);
    void getLoginInput(std::string& email, std::string& pass);
};
#endif