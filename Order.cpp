#include "order.h"

Order::Order(int id, Client* client, Restaurant* restaurant)
    : id(id), client(client), restaurant(restaurant), status(ORDERED), driver(nullptr) {}

int Order::getId() const {
    return id;
}

Client* Order::getClient() const {
    return client;
}

Restaurant* Order::getRestaurant() const {
    return restaurant;
}

const std::vector<std::pair<Item*, int>>& Order::getItems() const {
    return items;
}

OrderStatus Order::getStatus() const {
    return status;
}

Driver* Order::getDriver() const {
    return driver;
}

void Order::addItem(Item* item, int quantity) {
    items.emplace_back(item, quantity);
}

void Order::assignDriver(Driver* driver) {
    this->driver = driver;
}

void Order::updateStatus(OrderStatus status) {
    this->status = status;
}
