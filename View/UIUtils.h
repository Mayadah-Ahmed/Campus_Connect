#ifndef UIUTILS_H
#define UIUTILS_H
#include <iostream>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

namespace CampusConnect {
    namespace View {
        class UIUtils {
        public:
            static void showHeader() {
                std::cout << CYAN << BOLD;
                std::cout << "==============================================\n";
                std::cout << "           CAMPUS CONNECT v1.0\n";
                std::cout << "       Student Community Platform\n";
                std::cout << "==============================================\n\n" << RESET;
            }
            static void pauseScreen() {
                std::cout << CYAN << "\nPress Enter to continue..." << RESET;
                std::cin.ignore(1000, '\n');
                std::cin.get();
            }
        };
    }
}
#endif