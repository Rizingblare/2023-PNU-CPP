//
// Created by edward on 22. 1. 16..
//

#include <iostream>
#include "Reservation.h"
#include "Screening.h"

Reservation::Reservation(Customer customer, std::shared_ptr<Screening> screening, Money fee, int audienceCount)
    : customer(customer), screening(std::move(screening)), fee(fee), audienceCount(audienceCount) {}

std::ostream &operator<<(std::ostream &os, const Reservation &reservation){
    os << (*reservation.screening) << std::endl;
    os << "Customer: " << reservation.customer << ", Number of People: " << reservation.audienceCount << ", fee: " << reservation.fee;
    return os;
};