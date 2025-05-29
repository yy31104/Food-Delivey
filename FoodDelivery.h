#ifndef FOODDELIVERY_H
#define FOODDELIVERY_H

#include <vector>
#include "client.h"
#include "driver.h"
#include "restaurant.h"
#include "order.h"
#include "orderstatus.h"
#include <algorithm>

class FoodDelivery {
public:
    static Client* findClientById(const FoodDelivery& fd, int clientId);
    static Driver* findDriverById(const FoodDelivery& fd, int driverId);
    static Restaurant* findRestaurantById(const FoodDelivery& fd, int restaurantId);
    static Order* findOrderById(const FoodDelivery& fd, int orderId);
    static Item* findItemById(const FoodDelivery& fd, int restaurantId, const std::string& itemName);
    FoodDelivery();

    bool addClient(const Client& client);
    bool addDriver(const Driver& driver);
    bool addRestaurant(const Restaurant& restaurant);
    bool addOrder(const Order& order);
    bool updateOrderStatus(int orderId, OrderStatus status);
    bool assignDriverToOrder(int orderId);
    bool removeClient(int clientId);
    bool removeDriver(int driverId);
    bool removeRestaurant(int restaurantId);
    bool removeOrder(int orderId);

    const std::vector<Order>& getOrders() const;

private:
    Client* findClientById(int clientId) const;
    Driver* findDriverById(int driverId) const;
    Restaurant* findRestaurantById(int restaurantId) const;
    Order* findOrderById(int orderId) const;
    Item* findItemById(int restaurantId, const std::string& itemName) const;
private:
    std::vector<Client> clients;
    std::vector<Driver> drivers;
    std::vector<Restaurant> restaurants;
    std::vector<Order> orders;
};

#endif // FOODDELIVERY_H
