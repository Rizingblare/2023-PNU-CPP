//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_RESERVATION_H
#define WEEK11_RESERVATION_H
#include <memory>
#include <ostream>
#include "Customer.h"
#include "Money.h"

class Screening;
class Reservation {
public:
    Reservation() = default;
    Reservation(Customer customer, std::shared_ptr<Screening> screening, Money fee, int audienceCount);
private:
public:
    friend std::ostream &operator<<(std::ostream &os, const Reservation &reservation);

private:
    Customer customer;
    std::shared_ptr<Screening> screening;
    Money fee;
    int audienceCount;
};

#endif //WEEK11_RESERVATION_H
