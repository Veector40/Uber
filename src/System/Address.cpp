#include "../../include/System/Address.h"

Address::Address() : name("Unknown"), x(0), y(0) {
}

Address::Address(const MyString& name, int x, int y, const MyString& additionalInfo) :
    name(name), x(x), y(y), additionalInfo(additionalInfo) {
}

MyString Address::getName() const {
    return this->name;
}

int Address::getX() const {
    return this->x;
}

int Address::getY() const {
    return this->y;
}

MyString Address::getAdditionalInfo() const {
    return this->additionalInfo;
}

void Address::setName(const MyString& name) {
    this->name = name;
}

void Address::setX(int x) {
    this->x = x;
}

void Address::setY(int y) {
    this->y = y;
}

void Address::setAdditionalInfo(const MyString& additionalInfo) {
    this->additionalInfo = additionalInfo;
}
