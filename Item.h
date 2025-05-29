#ifndef ITEM_H
#define ITEM_H

#include <string>

// The Item class represents a menu item in the restaurant.
class Item {
public:
    // Constructor to initialize the item with name, price, and description.
    Item(const std::string& name, double price, const std::string& description);

    // Getter for item name.
    std::string getName() const;

    // Getter for item price.
    double getPrice() const;

    // Getter for item description.
    std::string getDescription() const;

private:
    std::string name;         // Item name
    double price;             // Item price
    std::string description;  // Item description
};

#endif // ITEM_H
