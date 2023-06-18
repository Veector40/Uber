#include "../../include/Utils/MyString.h"

MyString::MyString() : data(nullptr), length(0) {}

MyString::~MyString() {
    delete[] data;
}

MyString::MyString(const MyString& other) : length(other.length) {
    data = new char[length + 1];
    strcpy(data, other.data);
}

MyString::MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

MyString::MyString(const char* string) : length(strlen(string)) {
    data = new char[length + 1];
    strcpy(data, string);
}

size_t MyString::getLength() const {
    return length;
}

const char* MyString::getCString() const {
    return data;
}

MyString& MyString::operator+=(const MyString& rhs) {
    size_t newLength = length + rhs.length;
    char* newData = new char[newLength + 1];
    strcpy(newData, data);
    strcat(newData, rhs.data);
    delete[] data;
    data = newData;
    length = newLength;
    return *this;
}


MyVector<MyString> MyString::split(char delimiter) const {
    MyVector<MyString> result;
    size_t start = 0;
    size_t end = std::strchr(data, delimiter) - data;

    while (end <= length) {
        char* temp = new char[end - start + 1];
        std::strncpy(temp, data + start, end - start);
        temp[end - start] = '\0';
        result.push_back(MyString(temp));
        delete[] temp;
        start = end + 1;
        end = std::strchr(data + start, delimiter) - data;
    }

    if (start < length) {
        char* temp = new char[length - start + 1];
        std::strncpy(temp, data + start, length - start);
        temp[length - start] = '\0';
        result.push_back(MyString(temp));
        delete[] temp;
    }

    return result;
}

bool MyString::operator==(const MyString& rhs) const {
    if (getLength() != rhs.getLength()) {
        return false;
    }
    return strcmp(getCString(), rhs.getCString()) == 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.getCString();
    return os;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    size_t newLength = lhs.getLength() + rhs.getLength();
    char* newData = new char[newLength + 1];
    strcpy(newData, lhs.getCString());
    strcat(newData, rhs.getCString());
    MyString result(newData);
    delete[] newData;
    return result;
}

std::ostream& operator<<(const std::ostream& os, const MyString& str) {
    return os << str.getCString();
}
