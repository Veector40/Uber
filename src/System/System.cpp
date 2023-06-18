#include "../../include/System/System.h"

System* System::instance = nullptr;

System* System::getInstance() {
    if (instance == nullptr) {
        instance = new System();
    }

    return instance;
}
void System::registerClient(const MyString& username, const MyString& password, const MyString& firstName,
           const MyString& lastName, const MyString& phoneNumber) {
    Client newClient(username, password, firstName, lastName, phoneNumber);
    clients.push_back(newClient);
}

void System::registerDriver(const MyString& username, const MyString& password, const MyString& firstName,
           const MyString& lastName, const MyString& phoneNumber, const MyString& carNumber) {
    Driver newDriver(username, password, firstName, lastName, phoneNumber, carNumber);
    drivers.push_back(newDriver);
}

void System::login(const MyString& username, const MyString& password) {
    for (auto& client : clients) {
        if (client.getUsername() == username && client.getPassword() == password) {
            currentUser = &client;
            return;
        }
    }
    for (auto& driver : drivers) {
        if (driver.getUsername() == username && driver.getPassword() == password) {
            currentUser = &driver;
            return;
        }
    }
    std::cout << "Invalid credentials" << std::endl;
}

void System::logout() {
    currentUser = nullptr;
}

void System::notifyDrivers(const Order& order) {
    for (Driver& driver : drivers) {
        if (driver.isAvailable()) {
            driver.notifyOrder(order);
        }
    }
}

void System::cancelOrder(const Order& order) {
    if (order.getStatus() != OrderStatus::Completed) {
        Driver& driver = getDriver(order.getDriverName());
        driver.notifyCancellation(order);   
    }
}

void System::payForOrder(const Order& order, double amount) {
    if (order.getStatus() == OrderStatus::Completed) {
        Driver& driver = getDriver(order.getDriverName());
        driver.acceptPayment(order.getId(), amount);
    }
}

void System::rateDriver(const MyString& driverName, int rating) {
    Driver& driver = getDriver(driverName);
    driver.updateRating(rating);
}

Order& System::getOrder(const MyString& orderId) {
    for (auto& order : orders) {
        if (order.getId() == orderId) {
            return order;
        }
    }
    throw std::runtime_error("Order not found");
}

Driver& System::getDriver(const MyString& driverName) {
    for (auto& driver : drivers) {
        if (driver.getFirstName() + " " + driver.getLastName() == driverName) {
            return driver;
        }
    }
    throw std::runtime_error("Driver not found");
}