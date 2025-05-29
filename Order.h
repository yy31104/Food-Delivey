#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "client.h"
#include "restaurant.h"
#include "item.h"
#include "orderstatus.h"

class Client;
class Restaurant;
class Item;
class Driver;

class Order {
public:
    Order(int id, Client* client, Restaurant* restaurant);

    int getId() const;
    Client* getClient() const;
    Restaurant* getRestaurant() const;
    const std::vector<std::pair<Item*, int>>& getItems() const;
    OrderStatus getStatus() const;
    Driver* getDriver() const;

    void addItem(Item* item, int quantity);
    void assignDriver(Driver* driver);
    void updateStatus(OrderStatus status);

private:
    int id;
    Client* client;
    Restaurant* restaurant;
    std::vector<std::pair<Item*, int>> items;
    OrderStatus status;
    Driver* driver;
};

#endif // ORDER_H
