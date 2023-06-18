#ifndef ADDRESS_H
#define ADDRESS_H

#include "../Utils/MyString.h"


class Address {
public:
    Address();
    Address(const MyString& name, int x, int y, const MyString& additionalInfo);

    MyString getName() const;
    int getX() const;
    int getY() const;
    MyString getAdditionalInfo() const;

    void setName(const MyString& name);
    void setX(int x);
    void setY(int y);
    void setAdditionalInfo(const MyString& additionalInfo);

private:
    MyString name;
    int x;
    int y;
    MyString additionalInfo;
};

#endif // ADDRESS_H
