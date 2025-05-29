#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(int id, const std::string& name, const std::string& phone, const std::string& address);

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getAddress() const;

private:
    int id;
    std::string name;
    std::string phone;
    std::string address;
};

#endif // CLIENT_H
