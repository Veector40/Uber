#include "include/System/System.h"
#include "include/System/UserCommand.h"

int main() {
    // Working example with different cases
    
    // Register some clients
    System::getInstance()->registerClient("client1", "password1", "John", "Doe", "123456789");
    System::getInstance()->registerClient("client2", "password2", "Jane", "Smith", "987654321");

    // Register some drivers
    System::getInstance()->registerDriver("driver1", "password1", "Driver", "One", "111222333", "CAR111");
    System::getInstance()->registerDriver("driver2", "password2", "Driver", "Two", "444555666", "CAR222");

    // Clients log in and make orders
    System::getInstance()->login("client1", "password1");
    UserCommand command1(*System::getInstance()->getCurrentUser());
    command1.executeCommand("order 123 Main St 456 Oak St 2");
    System::getInstance()->logout();

    System::getInstance()->login("client2", "password2");
    UserCommand command2(*System::getInstance()->getCurrentUser());
    command2.executeCommand("order 789 Pine St 321 Elm St 3");
    System::getInstance()->logout();

    // Drivers log in, check messages and accept orders
    System::getInstance()->login("driver1", "password1");
    Driver& driver1 = dynamic_cast<Driver&>(*System::getInstance()->getCurrentUser());
    driver1.checkMessages();
    driver1.acceptOrder("angel40", 12);
    System::getInstance()->logout();

    System::getInstance()->login("driver2", "password2");
    Driver& driver2 = dynamic_cast<Driver&>(*System::getInstance()->getCurrentUser());
    driver2.checkMessages();
    driver2.acceptOrder("1", 45); 
    System::getInstance()->logout();

    // Client logs in and checks their orders
    System::getInstance()->login("client1", "password1");
    UserCommand command3(*System::getInstance()->getCurrentUser());
    command3.executeCommand("checkorder 0");
    System::getInstance()->logout();

    // Client cancels order
    System::getInstance()->login("client2", "password2");
    UserCommand command4(*System::getInstance()->getCurrentUser());
    command4.executeCommand("cancelorder 1");
    System::getInstance()->logout();

    // Driver logs in and checks their messages
    System::getInstance()->login("driver2", "password2");
    Driver& driver3 = dynamic_cast<Driver&>(*System::getInstance()->getCurrentUser());
    driver3.checkMessages();
    System::getInstance()->logout();

    return 0;
}