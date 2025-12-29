#ifndef POSTVIEW_H
#define POSTVIEW_H

#include <vector>
#include <string>
#include <memory>
#include "../models/Post.h"

namespace CampusConnect {
    namespace View {
        class PostView {
        public:
            
            void displayFeed(const std::vector<std::shared_ptr<Models::Post>>& posts);

           
            void promptForPost(std::string& content);

         
            void showMessage(std::string msg, bool isError = false);
        };
    }
}
#endif