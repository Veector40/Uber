#ifndef USER_H
#define USER_H


#include "../Utils/MyString.h"

class User {
public:
    User() = default;
    User(const MyString& username, const MyString& password,
         const MyString& firstName, const MyString& lastName);
    User(const User& other);
    User(User&& other) noexcept; 
    User& operator=(const User& other); 
    User& operator=(User&& other) noexcept;

    MyString getUsername() const;
    void setUsername(const MyString& username);
    MyString getPassword() const;
    void setPassword(const MyString& password);
    MyString getFirstName() const;
    void setFirstName(const MyString& firstName);
    MyString getLastName() const;
    void setLastName(const MyString& lastName);

    virtual MyString getUserType() const = 0;

private:
    MyString username;
    MyString password;
    MyString firstName;
    MyString lastName;
};

#endif // USER_H
