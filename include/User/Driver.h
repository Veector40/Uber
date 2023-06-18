#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"
#include "../System/Order.h"


class Driver : public User {
public:
    Driver() {}
    Driver(const MyString& username, const MyString& password, const MyString& firstName,
           const MyString& lastName, const MyString& phoneNumber,  const MyString& carNumber);

    void changeAddress(const Address& newAddress);
    void checkMessages();
    void acceptOrder(const MyString& orderId, int minutes);
    void declineOrder(const MyString& orderId);
    void finishOrder(const MyString& orderId);
    void acceptPayment(const MyString& orderId, double amount);

    double getRating() const;
    void updateRating(int newRating);
    bool isAvailable() const;
    void notifyOrder(const Order& order);
    void notifyCancellation(const Order& order);

    MyString getUserType() const override;

private:
    Address currentAddress;
    MyString carNumber;
    MyString phoneNumber;
    double balance;
    int rating;
    int ratingCount;
    bool available;

    MyVector<MyString> messages;
    MyVector<Order> orders;
    
};

#endif // DRIVER_H
