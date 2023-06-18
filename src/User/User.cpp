#include "../../include/User/User.h"

User::User(const MyString& username, const MyString& password,
           const MyString& firstName, const MyString& lastName)
    : username(username), password(password), firstName(firstName), lastName(lastName) {}

User::User(const User& other)
    : username(other.username), password(other.password), firstName(other.firstName), lastName(other.lastName) {}


User::User(User&& other) noexcept
    : username(std::move(other.username)), password(std::move(other.password)),
      firstName(std::move(other.firstName)), lastName(std::move(other.lastName)) {}

User& User::operator=(const User& other) {
    if (this != &other) {
        username = other.username;
        password = other.password;
        firstName = other.firstName;
        lastName = other.lastName;
    }
    return *this;
}

User& User::operator=(User&& other) noexcept {
    if (this != &other) {
        username = std::move(other.username);
        password = std::move(other.password);
        firstName = std::move(other.firstName);
        lastName = std::move(other.lastName);
    }
    return *this;
}

MyString User::getUsername() const {
    return username;
}

void User::setUsername(const MyString& username) {
    this->username = username;
}

MyString User::getPassword() const {
    return password;
}

void User::setPassword(const MyString& password) {
    this->password = password;
}

MyString User::getFirstName() const {
    return firstName;
}

void User::setFirstName(const MyString& firstName) {
    this->firstName = firstName;
}

MyString User::getLastName() const {
    return lastName;
}

void User::setLastName(const MyString& lastName) {
    this->lastName = lastName;
}
