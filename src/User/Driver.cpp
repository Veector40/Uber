#include "../../include/User/Driver.h"
#include "../../include/System/System.h"

Driver::Driver(const MyString& username, const MyString& password, const MyString& firstName,
               const MyString& lastName, const MyString& carNumber, const MyString& phoneNumber)
    : User(username, password, firstName, lastName),
      carNumber(carNumber),
      phoneNumber(phoneNumber),
      balance(0),
      rating(0),
      ratingCount(0),
      available(true) {
}

void Driver::changeAddress(const Address& newAddress) {
    currentAddress = newAddress;
}

void Driver::checkMessages() {
    for (const auto& message : messages) {
        std::cout << message.getCString() << std::endl;
    }
    
    messages.~MyVector();
}


void Driver::acceptOrder(const MyString& orderId, int minutes) {
    Order& order = System::getInstance()->getOrder(orderId);
    order.setStatus(OrderStatus::Accepted);
    order.setDriverName(getUsername());
    order.setArrivalTime(minutes);
}

void Driver::declineOrder(const MyString& orderId) {
    Order& order = System::getInstance()->getOrder(orderId);
}

void Driver::finishOrder(const MyString& orderId) {
    Order& order = System::getInstance()->getOrder(orderId);
    order.setStatus(OrderStatus::Completed);
    currentAddress = order.getDestination();
}

void Driver::acceptPayment(const MyString& orderId, double amount) {
    balance += amount;
}

double Driver::getRating() const {
    return (ratingCount > 0) ? (rating / static_cast<double>(ratingCount)) : 0.0;
}

void Driver::updateRating(int newRating) {
    rating += newRating;
    ratingCount++;
}

bool Driver::isAvailable() const {
    return available;
}

void Driver::notifyOrder(const Order& order) {
    orders.push_back(order);
    MyString message = "New order from " + order.getPickup().getName() + " to " + order.getDestination().getName();
    messages.push_back(message);
}



void Driver::notifyCancellation(const Order& cancelledOrder) {
    
    for (auto& order : orders) {
        if (order.getId() == cancelledOrder.getId()) {
            orders.remove(order);
            break;
        }
    }
    MyString message = "Order from " + cancelledOrder.getPickup().getName() + " to " + cancelledOrder.getDestination().getName() + " was cancelled.";
    messages.push_back(message);
}

MyString Driver::getUserType() const {
    return "Driver";
}