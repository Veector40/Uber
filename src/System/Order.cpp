#include "../../include/System/Order.h"


MyString Order::generateId() const {
    std::time_t currentTime = std::time(nullptr);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));

    return MyString(buffer);
}

Order::Order(const MyString& clientUsername,
             const Address& pickup, const Address& destination, int passengers) :
    clientUsername(clientUsername), pickup(pickup), destination(destination),
    passengers(passengers), status(OrderStatus::Pending) {
}


void Order::printDetails() const {
    std::cout << "Order ID: " << id << std::endl;
    std::cout << "Client: " << clientUsername << std::endl;
    std::cout << "Pickup: " << pickup.getName() << std::endl;
    std::cout << "Destination: " << destination.getName() << std::endl;
    std::cout << "Passengers: " << passengers << std::endl;
    std::cout << "Status: " << (status == OrderStatus::Pending ? "Pending" : "Completed") << std::endl;
}

void Order::cancel() {
    status = OrderStatus::Cancelled;
}

const MyString& Order::getId() const {
    return id;
}

const MyString& Order::getClientUsername() const {
    return clientUsername;
}

const Address& Order::getPickup() const {
    return pickup;
}

const Address& Order::getDestination() const {
    return destination;
}

int Order::getPassengers() const {
    return passengers;
}

int Order::getArrivalTime() const {
    return arrivalTime;
}

OrderStatus Order::getStatus() const {
    return status;
}

const MyString& Order::getDriverName() const { return driverName; }

void Order::setId(const MyString& id) {
    this->id = id;
}

void Order::setArrivalTime(int minutes) {
    this->arrivalTime = arrivalTime;
}


void Order::setClientUsername(const MyString& clientUsername) {
    this->clientUsername = clientUsername;
}

void Order::setPickup(const Address& pickup) {
    this->pickup = pickup;
}

void Order::setDestination(const Address& destination) {
    this->destination = destination;
}

void Order::setPassengers(int passengers) {
    this->passengers = passengers;
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

void Order::setDriverName(const MyString& name) { driverName = name; }


bool Order::operator==(const Order& other) const {
        return id == other.id;  // compare based on the id
    }

bool Order::operator!=(const Order& other) const {
    return !(*this == other);
}