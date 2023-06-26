//
// Created by edward on 22. 1. 16..
//
#include <iostream>
#include <memory>
#include <iomanip>
#include "Screening.h"

Screening::Screening(Movie movie, int sequence, std::tm whenScreened)
    : movie(movie), sequence(sequence), whenScreened(whenScreened) {}

std::tm Screening::getStartTime(){
    return whenScreened;
}
bool Screening::isSequence(int sequence){
    return this->sequence == sequence;
}
Money Screening::getMovieFee() {
    return movie.getFee();
}
Reservation Screening::reserve(Customer customer, int audienceCount) {
    return Reservation{customer, shared_from_this(), calculateFee(audienceCount), audienceCount};
}

Money Screening::calculateFee(int audienceCount) {
    return movie.calculateMovieFee(*this).times(audienceCount);
}

std::ostream &operator<<(std::ostream &os, const Screening &screening) {
    os << "Movie: " << screening.movie << ", sequence: " << screening.sequence << ", startTime: " << std::put_time(&screening.whenScreened, "%Y-%m-%d %H:%M");
    return os;
}