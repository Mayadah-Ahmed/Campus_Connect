#ifndef INMEMORYUSERREPOSITORY_H
#define INMEMORYUSERREPOSITORY_H
#include "IUserRepository.h"
#include <vector>

class InMemoryUserRepository : public IUserRepository {
private:
    std::vector<User> users;
public:
    void saveUser(User user) override;
    User* findByEmail(std::string email) override;
};
#endif