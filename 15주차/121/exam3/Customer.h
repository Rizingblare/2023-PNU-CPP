//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_CUSTOMER_H
#define WEEK11_CUSTOMER_H
#include <string>
#include <ostream>

class Customer {
public:
    Customer() = default;
    Customer(long id, std::string name) : id (id), name(name) {}
    friend std::ostream &operator<<(std::ostream &os, const Customer &customer) {
        os << "id: " << customer.id << ", name: " << customer.name;
        return os;
    }

private:
    long id;
    std::string name;
};

#endif //WEEK11_CUSTOMER_H
