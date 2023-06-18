#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <ctime>


#include "../Utils/MyString.h"
#include "Address.h"

enum class OrderStatus {
    Pending,
    Accepted,
    Completed,
    Cancelled
};

class Order {
public:
    Order() {}
    Order(const MyString& clientUsername,
          const Address& pickup, const Address& destination, int passengers);

    void printDetails() const;
    void cancel();
    
    const MyString& getId() const;
    const MyString& getClientUsername() const;
    const Address& getPickup() const;
    const Address& getDestination() const;
    int getPassengers() const;
    OrderStatus getStatus() const;
    const MyString& getDriverName() const;
    int getArrivalTime() const; 

    void setId(const MyString& id);
    void setClientUsername(const MyString& clientUsername);
    void setPickup(const Address& pickup);
    void setDestination(const Address& destination);
    void setPassengers(int passengers);
    void setStatus(OrderStatus status);
    void setDriverName(const MyString& name);
    void setArrivalTime(int minutes);

    
    bool operator==(const Order& other) const;
    bool operator!=(const Order& other) const;
    
private:
    MyString id;
    MyString clientUsername;
    MyString driverName;
    Address pickup;
    Address destination;
    int passengers;
    int arrivalTime;
    OrderStatus status;

    MyString generateId() const;
};

#endif // ORDER_H
