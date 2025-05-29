#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <string>
#include "item.h"
#include "order.h"

class Order;

class Restaurant {
public:
    Restaurant(int id, const std::string& name, const std::string& address);

    int getId() const;
    std::string getName() const;
    std::string getAddress() const;

    void addItem(Item* item);
    void removeItem(Item* item);
    const std::vector<Item*>& getMenu() const;

    void addOrder(Order* order);
    const std::vector<Order*>& getOrders() const;

private:
    int id;
    std::string name;
    std::string address;
    std::vector<Item*> menu;
    std::vector<Order*> orders;
};

#endif // RESTAURANT_H
