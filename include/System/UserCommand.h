#ifndef USERCOMMAND_H
#define USERCOMMAND_H

#include "../User/User.h"

class UserCommand {
public:
    UserCommand(User& user);

    void executeCommand(const MyString& commandLine);

private:
    User& user;
};

#endif // USERCOMMAND_H
