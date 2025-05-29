#include "client.h"

Client::Client(int id, const std::string& name, const std::string& phone, const std::string& address)
    : id(id), name(name), phone(phone), address(address) {}

int Client::getId() const {
    return id;
}

std::string Client::getName() const {
    return name;
}

std::string Client::getPhone() const {
    return phone;
}

std::string Client::getAddress() const {
    return address;
}
