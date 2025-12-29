#ifndef USERVIEW_H
#define USERVIEW_H
#include <string>

namespace CampusConnect {
    namespace View {
        class UserView {
        public:
            void showAbout();
            void showMessage(std::string msg, bool isError = false);
            void getRegistrationInput(std::string& name, std::string& email, std::string& sid, std::string& pass);
        };
    }
}
#endif