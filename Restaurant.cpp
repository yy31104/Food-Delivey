#include "restaurant.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

Restaurant::Restaurant(int id, const std::string& name, const std::string& address)
    : id(id), name(name), address(address) {}

int Restaurant::getId() const {
    return id;
}

std::string Restaurant::getName() const {
    return name;
}

std::string Restaurant::getAddress() const {
    return address;
}

void Restaurant::addItem(Item* item) {
    menu.push_back(item);
}

void Restaurant::removeItem(Item* item) {
    if (menu.empty()) {
        std::cerr << "Error: Cannot remove item from an empty restaurant." << std::endl;
        return;
    }

    auto it = std::remove(menu.begin(), menu.end(), item);
    if (it != menu.end()) {
        menu.erase(it, menu.end());
    }
}

const std::vector<Item*>& Restaurant::getMenu() const {
    return menu;
}

void Restaurant::addOrder(Order* order) {
    orders.push_back(order);
}

const std::vector<Order*>& Restaurant::getOrders() const {
    return orders;
}
