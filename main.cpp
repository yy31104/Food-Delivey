#include <cassert>
#include <iostream>
#include "client.h"
#include "restaurant.h"
#include "order.h"
#include "driver.h"
#include "item.h"
#include "fooddelivery.h"
#include "orderstatus.h"

void testClient(FoodDelivery& fd) {
    Client* client1 = new Client(1, "Alice", "1234567890", "123 Main St");
    Client* client2 = new Client(1, "Bob", "0987654321", "456 Elm St");

    assert(fd.addClient(*client1) == true);
    assert(fd.addClient(*client2) == false);

    assert(client1->getId() == 1);
    assert(client1->getName() == "Alice");
    assert(client1->getPhone() == "1234567890");
    assert(client1->getAddress() == "123 Main St");

    Client* clientNegativeId = new Client(-1, "Negative", "0000000000", "Negative St");
    assert(fd.addClient(*clientNegativeId) == false);

    delete client1;
    delete client2;
    delete clientNegativeId;

    std::cout << "Client class test passed." << std::endl;
}

void testDriver(FoodDelivery& fd) {
    Driver* driver1 = new Driver(1, "Jane Doe");
    Driver* driver2 = new Driver(1, "John Doe");

    assert(fd.addDriver(*driver1) == true);
    assert(fd.addDriver(*driver2) == false);

    assert(driver1->getId() == 1);
    assert(driver1->getName() == "Jane Doe");

    Driver* driverNegativeId = new Driver(-1, "Negative");
    assert(fd.addDriver(*driverNegativeId) == false);

    delete driver1;
    delete driver2;
    delete driverNegativeId;

    std::cout << "Driver class test passed." << std::endl;
}

void testRestaurant(FoodDelivery& fd) {
    Restaurant* restaurant1 = new Restaurant(1, "Pizza Place", "123 Main St");
    Restaurant* restaurant2 = new Restaurant(1, "Burger Joint", "456 Elm St");

    assert(fd.addRestaurant(*restaurant1) == true);
    assert(fd.addRestaurant(*restaurant2) == false);

    assert(restaurant1->getId() == 1);
    assert(restaurant1->getName() == "Pizza Place");
    assert(restaurant1->getAddress() == "123 Main St");

    Restaurant* restaurantNegativeId = new Restaurant(-1, "Negative", "Negative St");
    assert(fd.addRestaurant(*restaurantNegativeId) == false);

    Item* pizza= new Item("Pizza", 10.0, "Cheese, Tomato, Dough");
    restaurant1->addItem(pizza);
    assert(restaurant1->getMenu().size() == 1);
    assert(restaurant1->getMenu()[0]->getName() == "Pizza");
    assert(restaurant1->getMenu()[0]->getPrice() == 10.0);
    assert(restaurant1->getMenu()[0]->getDescription() == "Cheese, Tomato, Dough");

    Client* client1 = new Client(1, "Alice", "1234567890", "123 Main St");
    Order* order1 = new Order(1, client1, restaurant1);
    restaurant1->addOrder(order1);
    assert(fd.addClient(*client1) == true);
    assert(fd.addOrder(*order1) == true);
    
    assert(restaurant1->getOrders().size() == 1);
    assert(restaurant1->getOrders()[0]->getId() == 1);

    delete client1;
    delete order1;
    delete pizza;
    delete restaurant1;
    delete restaurant2;
    delete restaurantNegativeId;

    std::cout << "Restaurant class test passed." << std::endl;
}
void testRemoveRestaurant(FoodDelivery& fd) {
    Restaurant* restaurant = new Restaurant(2, "Sushi Bar", "789 Oak St");
    assert(fd.addRestaurant(*restaurant) == true);

    Item* sushi = new Item("Sushi", 15.0, "Rice, Fish, Seaweed");
    restaurant->addItem(sushi);
    assert(restaurant->getMenu().size() == 1);

    Client* client = new Client(2, "Bob", "1234567890", "456 Elm St");
    assert(fd.addClient(*client) == true);
    Order* order = new Order(2, client, restaurant);
    order->addItem(sushi, 1);
    assert(fd.addOrder(*order) == true);

    // Remove the orders associated with the restaurant
    assert(fd.removeOrder(2) == true);

    // Remove the restaurant
    bool result = fd.removeRestaurant(2);
    assert(result == true);

    // Now check if orders and menu are empty
    assert(restaurant->getOrders().empty());
    assert(!restaurant->getMenu().empty());

    delete client;
    delete order;
    delete sushi;
    delete restaurant;

    std::cout << "Remove Restaurant test passed." << std::endl;
}

void testRemoveItemFromEmptyRestaurant(FoodDelivery& fd) {
    Restaurant* restaurant = new Restaurant(6, "Empty Restaurant", "100 No Item St");
    assert(fd.addRestaurant(*restaurant) == true);

    // Attempt to remove an item from an empty restaurant
    Item* nonExistentItem = new Item("NonExistent", 0.0, "This item does not exist");

    // Attempt to remove item
    restaurant->removeItem(nonExistentItem);

    delete restaurant;
    delete nonExistentItem;

    std::cout << "Remove Item from Empty Restaurant test passed." << std::endl;
}

void testRemoveClient(FoodDelivery& fd) {
    Client* client = new Client(3, "Charlie", "1112223333", "789 Oak St");
    assert(fd.addClient(*client) == true);

    Restaurant* restaurant = new Restaurant(3, "Taco Place", "789 Oak St");
    assert(fd.addRestaurant(*restaurant) == true);

    Order* order = new Order(3, client, restaurant);
    assert(fd.addOrder(*order) == true);

    
    assert(fd.removeClient(3) == true);
    assert(fd.removeClient(3) == false);

    delete client;
    delete restaurant;
    delete order;

    std::cout << "Remove Client test passed." << std::endl;
}

void testRemoveDriver(FoodDelivery& fd) {
    Driver* driver = new Driver(4, "Dave");
    assert(fd.addDriver(*driver) == true);

    Client* client = new Client(4, "Eve", "4445556666", "101 Pine St");
    assert(fd.addClient(*client) == true);

    Restaurant* restaurant = new Restaurant(4, "Burger Place", "101 Pine St");
    assert(fd.addRestaurant(*restaurant) == true);

    Order* order = new Order(4, client, restaurant);
    assert(fd.addOrder(*order) == true);
    assert(fd.assignDriverToOrder(4) == true);

    
    assert(fd.removeDriver(4) == true);

    for (const auto& ord : fd.getOrders()) {
        if (ord.getId() == 4) {
            //assert(ord.getDriver() == );
            assert(ord.getStatus() == ORDERED);
        }
    }

    delete driver;
    delete client;
    delete restaurant;
    delete order;

    std::cout << "Remove Driver test passed." << std::endl;
}

void testRemoveItem(FoodDelivery& fd) {
    Restaurant* restaurant = new Restaurant(5, "Steak House", "234 Maple St");
    assert(fd.addRestaurant(*restaurant) == true);

    Item* steak = new Item("Steak", 25.0, "Beef, Salt, Pepper");
    restaurant->addItem(steak);
    assert(restaurant->getMenu().size() == 1);

    Client* client = new Client(5, "Frank", "5556667777", "567 Birch St");
    assert(fd.addClient(*client) == true);
    Order* order = new Order(5, client, restaurant);
    order->addItem(steak, 2);
    assert(fd.addOrder(*order) == true);
    //assert(restaurant->getOrders().size() == 1);

    restaurant->removeItem(steak);
    assert(restaurant->getMenu().empty());
    assert(fd.removeOrder(5) == true);
    assert(restaurant->getOrders().empty());

    delete restaurant;
    delete steak;
    delete client;
    delete order;

    std::cout << "Remove Item test passed." << std::endl;
}

void testOrder(FoodDelivery& fd) {
    Client* client = new Client(1, "Alice", "1234567890", "123 Main St");
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", "123 Main St");

    Order* order1 = new Order(1, client, restaurant);
    Order* order2 = new Order(1, client, restaurant);

    assert(fd.addOrder(*order1) == true);
    assert(fd.addOrder(*order2) == false);

    assert(order1->getId() == 1);
    assert(order1->getClient() == client);
    assert(order1->getRestaurant() == restaurant);

    Order* orderNegativeId = new Order(-1, client, restaurant);
    assert(fd.addOrder(*orderNegativeId) == false);

    Item* pizza = new Item("Pizza", 10.0, "Cheese, Tomato, Dough");
    order1->addItem(pizza, 2);
    auto items = order1->getItems();
    assert(items.size() == 1);
    assert(items[0].first == pizza);
    assert(items[0].second == 2);

    /*assert(fd.updateOrderStatus(1, PREPARING) == true);
    assert(order1->getStatus() == PREPARING);*/

    Driver* driver1 = new Driver(1, "John Doe");
    assert(fd.addDriver(*driver1) == true);
    assert(fd.assignDriverToOrder(1) == true);
    /*assert(order1->getDriver() == driver1);
    assert(driver1->getAssignedOrderId() == 1);*/

    assert(fd.removeOrder(1) == true);
    assert(fd.removeOrder(1) == false);

    delete client;
    delete restaurant;
    delete order1;
    delete order2;
    delete orderNegativeId;
    delete pizza;
    delete driver1;

    std::cout << "Order class test passed." << std::endl;
}

void testFindFunctions(FoodDelivery& fd) {
    Client* client = new Client(1, "Alice", "1234567890", "123 Main St");
    assert(fd.addClient(*client) == true);

    Driver* driver = new Driver(1, "John Doe");
    assert(fd.addDriver(*driver) == true);

    Restaurant* restaurant = new Restaurant(1, "Pizza Place", "123 Main St");
    assert(fd.addRestaurant(*restaurant) == true);

    Item* pizza = new Item("Pizza", 10.0, "Cheese, Tomato, Dough");
    restaurant->addItem(pizza);
    assert(restaurant->getMenu().size() == 1);

    Order* order = new Order(1, client, restaurant);
    order->addItem(pizza, 2);
    assert(fd.addOrder(*order) == true);

    Client* foundClient = FoodDelivery::findClientById(fd, 1);
    assert(foundClient != nullptr && foundClient->getName() == "Alice");

    Driver* foundDriver = FoodDelivery::findDriverById(fd, 1);
    assert(foundDriver != nullptr && foundDriver->getName() == "John Doe");

    Restaurant* foundRestaurant = FoodDelivery::findRestaurantById(fd, 1);
    assert(foundRestaurant != nullptr && foundRestaurant->getName() == "Pizza Place");


    Order* foundOrder = FoodDelivery::findOrderById(fd, 1);
    assert(foundOrder != nullptr && foundOrder->getId() == 1);

    delete client;
    delete driver;
    delete restaurant;
    delete pizza;
    delete order;

    std::cout << "Find functions test passed." << std::endl;
}

int main() {
    FoodDelivery fd1;
    FoodDelivery fd2;
    FoodDelivery fd3;
    FoodDelivery fd4;
    FoodDelivery fd5;
    FoodDelivery fd6;
    FoodDelivery fd7;
    FoodDelivery fd8;
    FoodDelivery fd9;
    FoodDelivery fd0;
    testClient(fd1);
    testDriver(fd2);
    testRestaurant(fd3);
    testRemoveRestaurant(fd4);
    testRemoveItemFromEmptyRestaurant(fd5);
    testRemoveClient(fd6);
    testRemoveDriver(fd7);
    testRemoveItem(fd8);
    testOrder(fd9);
    testFindFunctions(fd0);

    return 0;
}
