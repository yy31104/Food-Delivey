#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>

// The Driver class represents a driver in the food delivery system.
class Driver {
public:
    // Constructor to initialize the driver with id and name.
    Driver(int id, const std::string& name);

    // Getter for driver ID.
    int getId() const;

    // Getter for driver name.
    std::string getName() const;

    // Getter for the assigned order ID.
    int getAssignedOrderId() const;

    // Assigns an order to the driver.
    void assignOrder(int orderId);

    // Marks the current order as completed.
    void completeOrder();

private:
    int id;                 // Driver ID
    std::string name;       // Driver name
    int assignedOrderId;    // ID of the order assigned to the driver
};

#endif // DRIVER_H
