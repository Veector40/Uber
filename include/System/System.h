#ifndef SYSTEM_H
#define SYSTEM_H

#include "../Utils/MyVector.h"
#include "../User/Client.h"
#include "../User/Driver.h"
#include "Order.h"

class System {
private:
    User* currentUser;
    MyVector<Client> clients;
    MyVector<Driver> drivers;
    MyVector<Order> orders;
    static System* instance;

    System() {}
public:
    System(const System&) = delete;
    System& operator=(const System&) = delete;

    static System* getInstance();

    void registerClient(const MyString& username, const MyString& password, const MyString& firstName,
           const MyString& lastName, const MyString& phoneNumber);    
    void registerDriver(const MyString& username, const MyString& password, const MyString& firstName,
           const MyString& lastName, const MyString& carNumber, const MyString& phoneNumber);
    User* getCurrentUser() const { return currentUser; }
    
    void login(const MyString& username, const MyString& password);
    void logout();
    void notifyDrivers(const Order& order);
    void cancelOrder(const Order& order);
    void payForOrder(const Order& order, double amount);
    void rateDriver(const MyString& driverName, int rating);

    Order& getOrder(const MyString& orderId);
    Driver& getDriver(const MyString& driverName);

    ~System() { delete currentUser; }
};

#endif //SYSTEM_H
