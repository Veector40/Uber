#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"
#include "../System/Order.h"
#include "../System/Address.h"
#include "../Utils/MyString.h"
#include "../Utils/MyVector.h"

class Client : public User {
public:
    Client() = default;
    Client(const MyString& username, const MyString& password,
           const MyString& firstName, const MyString& lastName,
           const MyString& phoneNumber);
    
    Client(const Client& other);

    Client(Client&& other) noexcept;

    Client& operator=(const Client& other);

    Client& operator=(Client&& other) noexcept;

    void orderTaxi(const Address& pickup, const Address& destination, int passengers);
    void checkOrder(const MyString& orderId) const;
    void cancelOrder(const MyString& orderId);

    MyString getUserType() const override;

private:
    MyVector<Order> orders;
    MyString phoneNumber;
};

#endif // CLIENT_H
