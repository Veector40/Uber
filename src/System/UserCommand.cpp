#include "../../include/System/UserCommand.h"
#include "../../include/System/System.h"

UserCommand::UserCommand(User& user) : user(user) {}


void UserCommand::executeCommand(const MyString& commandLine) {
    MyString command = commandLine.split(' ')[0];
    if (command == "register") {
        MyString type = commandLine.split(' ')[1];
        MyString username = commandLine.split(' ')[2];
        MyString password = commandLine.split(' ')[3];
        MyString firstName = commandLine.split(' ')[4];
        MyString lastName = commandLine.split(' ')[5];
        MyString phoneNumber = commandLine.split(' ')[6];
        if (type == "client") {
            System::getInstance()->registerClient(username, password, firstName, lastName, phoneNumber);
        } else if (type == "driver") {
            MyString carNumber = commandLine.split(' ')[7];
            System::getInstance()->registerDriver(username, password, firstName, lastName, phoneNumber, carNumber);
        }
    } else if (command == "login") {
        MyString username = commandLine.split(' ')[1];
        MyString password = commandLine.split(' ')[2];
        System::getInstance()->login(username, password);
    } else if (command == "logout") {
        System::getInstance()->logout();
    }
}
