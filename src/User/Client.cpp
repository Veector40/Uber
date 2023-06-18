#include "../../include/User/Client.h"
#include "../../include/System/System.h"

void Client::orderTaxi(const Address& pickup, const Address& destination, int passengers) {
    Order newOrder(getUsername(), pickup, destination, passengers);
    orders.push_back(newOrder);
    System::getInstance()->notifyDrivers(newOrder);
}

void Client::checkOrder(const MyString& orderId) const {
    for (const auto& order : orders) {
        if (order.getId() == orderId) {
            order.printDetails();
            return;
        }
    }
    std::cout << "Order not found" << std::endl;
}

void Client::cancelOrder(const MyString& orderId) {
    for (auto& order : orders) {
        if (order.getId() == orderId) {
            System::getInstance()->cancelOrder(order);
            return;
        }
    }
    std::cout << "Order not found" << std::endl;
}

MyString Client::getUserType() const {
    return "Client";
}