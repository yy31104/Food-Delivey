#include "fooddelivery.h"
#include <stdexcept>
#include <iostream>

// FriendHelper function implementations
Client* FoodDelivery::findClientById(const FoodDelivery& fd, int clientId) {
    return fd.findClientById(clientId);
}

Driver* FoodDelivery::findDriverById(const FoodDelivery& fd, int driverId) {
    return fd.findDriverById(driverId);
}

Restaurant* FoodDelivery::findRestaurantById(const FoodDelivery& fd, int restaurantId) {
    return fd.findRestaurantById(restaurantId);
}

Order* FoodDelivery::findOrderById(const FoodDelivery& fd, int orderId) {
    return fd.findOrderById(orderId);
}

Item* FoodDelivery::findItemById(const FoodDelivery& fd, int restaurantId, const std::string& itemName) {
    return fd.findItemById(restaurantId, itemName);
}

FoodDelivery::FoodDelivery() {}

bool FoodDelivery::addClient(const Client& client) {
    if (client.getId() <= 0) {
        std::cerr << "Error: Client ID cannot be zero or negative" << std::endl;
        return false;
    }
    if (FoodDelivery::findClientById(*this, client.getId())) {
        std::cerr << "Error: Duplicate client ID" << std::endl;
        return false;
    }
    clients.push_back(client);
    return true;
}

bool FoodDelivery::addDriver(const Driver& driver) {
    if (driver.getId() <= 0) {
        std::cerr << "Error: Driver ID cannot be zero or negative" << std::endl;
        return false;
    }
    if (FoodDelivery::findDriverById(*this, driver.getId())) {
        std::cerr << "Error: Duplicate driver ID" << std::endl;
        return false;
    }
    drivers.push_back(driver);
    return true;
}

bool FoodDelivery::addRestaurant(const Restaurant& restaurant) {
    if (restaurant.getId() <= 0) {
        std::cerr << "Error: Restaurant ID cannot be zero or negative" << std::endl;
        return false;
    }
    if (FoodDelivery::findRestaurantById(*this, restaurant.getId())) {
        std::cerr << "Error: Duplicate restaurant ID" << std::endl;
        return false;
    }
    restaurants.push_back(restaurant);
    return true;
}

bool FoodDelivery::addOrder(const Order& order) {
    if (order.getId() <= 0) {
        std::cerr << "Error: Order ID cannot be zero or negative" << std::endl;
        return false;
    }
    if (FoodDelivery::findOrderById(*this, order.getId())) {
        std::cerr << "Error: Duplicate order ID" << std::endl;
        return false;
    }
    orders.push_back(order);
    return true;
}


bool FoodDelivery::updateOrderStatus(int orderId, OrderStatus status) {
    Order* order = FoodDelivery::findOrderById(*this, orderId);
    if (order) {
        order->updateStatus(status);
        return true;
    }
    std::cerr << "Error: Order ID not found" << std::endl;
    return false;
}

bool FoodDelivery::assignDriverToOrder(int orderId) {
    Order* order = FoodDelivery::findOrderById(*this, orderId);
    if (order) {
        for (Driver& driver : drivers) {
            if (driver.getAssignedOrderId() == -1) {
                order->assignDriver(&driver);
                driver.assignOrder(orderId);
                return true;
            }
        }
    }
    return false;
}

bool FoodDelivery::removeClient(int clientId) {
    auto it = std::remove_if(clients.begin(), clients.end(),
        [clientId](const Client& client) { return client.getId() == clientId; });
    if (it != clients.end()) {
        clients.erase(it, clients.end());
        return true;
    }
    return false;
}

bool FoodDelivery::removeDriver(int driverId) {
    auto it = std::remove_if(drivers.begin(), drivers.end(),
        [driverId](const Driver& driver) { return driver.getId() == driverId; });
    if (it != drivers.end()) {
        drivers.erase(it, drivers.end());
        return true;
    }
    return false;
}

bool FoodDelivery::removeRestaurant(int restaurantId) {
    auto it = std::remove_if(restaurants.begin(), restaurants.end(),
        [restaurantId](const Restaurant& restaurant) { return restaurant.getId() == restaurantId; });
    if (it != restaurants.end()) {
        restaurants.erase(it, restaurants.end());
        return true;
    }
    return false;
}

bool FoodDelivery::removeOrder(int orderId) {
    auto it = std::remove_if(orders.begin(), orders.end(),
        [orderId](const Order& order) { return order.getId() == orderId; });
    if (it != orders.end()) {
        orders.erase(it, orders.end());
        return true;
    }
    return false;
}

const std::vector<Order>& FoodDelivery::getOrders() const {
    return orders;
}

Client* FoodDelivery::findClientById(int clientId) const {
    auto it = std::find_if(clients.begin(), clients.end(),
        [clientId](const Client& client) { return client.getId() == clientId; });
    return (it != clients.end()) ? const_cast<Client*>(&(*it)) : nullptr;
}

Driver* FoodDelivery::findDriverById(int driverId) const {
    auto it = std::find_if(drivers.begin(), drivers.end(),
        [driverId](const Driver& driver) { return driver.getId() == driverId; });
    return (it != drivers.end()) ? const_cast<Driver*>(&(*it)) : nullptr;
}

Restaurant* FoodDelivery::findRestaurantById(int restaurantId) const {
    auto it = std::find_if(restaurants.begin(), restaurants.end(),
        [restaurantId](const Restaurant& restaurant) { return restaurant.getId() == restaurantId; });
    return (it != restaurants.end()) ? const_cast<Restaurant*>(&(*it)) : nullptr;
}

Order* FoodDelivery::findOrderById(int orderId) const {
    auto it = std::find_if(orders.begin(), orders.end(),
        [orderId](const Order& order) { return order.getId() == orderId; });
    return (it != orders.end()) ? const_cast<Order*>(&(*it)) : nullptr;
}

Item* FoodDelivery::findItemById(int restaurantId, const std::string& itemName) const {
    Restaurant* restaurant = findRestaurantById(restaurantId);
    if (restaurant) {
        auto& menu = restaurant->getMenu();
        auto it = std::find_if(menu.begin(), menu.end(),
            [&itemName](const Item* item) { return item->getName() == itemName; });
        return (it != menu.end()) ? *it : nullptr;
    }
    return nullptr;
}
