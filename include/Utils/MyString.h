#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <ostream>
#include <cstring>

#include "MyVector.h"

class MyString
{
private:
    char* data;
    size_t length; 

public:
    MyString();
    ~MyString();  

    MyString(const MyString& other);

    MyString(MyString&& other) noexcept;

    MyString& operator=(const MyString& other);

    MyString& operator=(MyString&& other) noexcept;

    MyString(const char* string);

    size_t getLength() const;

    const char* getCString() const;

    MyString& operator+=(const MyString& rhs);

    MyVector<MyString> split(char delimiter) const;

    bool operator==(const MyString& rhs) const;
 
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::ostream& operator<<(const std::ostream& os, const MyString& str);
};

#endif // MYSTRING_H