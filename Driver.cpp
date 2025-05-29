#include "driver.h"

// Constructor for the Driver class, initializes id, name, and assignedOrderId.
Driver::Driver(int id, const std::string& name)
    : id(id), name(name), assignedOrderId(-1) {
    // Validates that ID is not zero.
    if (id == 0) {
        std::cerr << "Error: Driver ID cannot be zero" << std::endl;
    }
    // Validates that the name is not empty.
    if (name.empty()) {
        std::cerr << "Error: Driver name cannot be empty" << std::endl;
    }
    if (id <= 0) {
        std::cerr << "Error: Driver ID cannot be zero or negative" << std::endl;
    }
}

// Returns driver ID.
int Driver::getId() const {
    return id;
}

// Returns driver name.
std::string Driver::getName() const {
    return name;
}

// Returns the ID of the assigned order.
int Driver::getAssignedOrderId() const {
    return assignedOrderId;
}

// Assigns an order to the driver.
void Driver::assignOrder(int orderId) {
    // Validates that the order ID is positive.
    if (orderId <= 0) {
        std::cerr << "Error: Order ID must be positive" << std::endl;
    }
    // Validates that the driver does not already have an assigned order.
    if (assignedOrderId != -1) {
        std::cerr << "Error: Driver already has an assigned order" << std::endl;
    }
    else {
        assignedOrderId = orderId;
    }
}

// Marks the current order as completed by resetting assignedOrderId.
void Driver::completeOrder() {
    assignedOrderId = -1;
}
