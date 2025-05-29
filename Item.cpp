#include "item.h"
#include <stdexcept>
#include <iostream>

// Constructor for the Item class, initializes name, price, and description.
Item::Item(const std::string& name, double price, const std::string& description)
    : name(name), price(price), description(description) {
    // Validates that the name is not empty.
    if (name.empty()) {
        std::cerr << "Error: Item name cannot be empty" << std::endl;
        this->price = -1;
    }
    // Validates that the price is positive.
    if (price <= 0) {
        std::cerr << "Error: Item price must be positive" << std::endl;
        this->price = -1;
    }
}

// Returns item name.
std::string Item::getName() const {
    return name;
}

// Returns item price.
double Item::getPrice() const {
    return price;
}

// Returns item description.
std::string Item::getDescription() const {
    return description;
}
