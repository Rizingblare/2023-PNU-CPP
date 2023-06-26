//
// Created by edward on 22. 1. 16..
//
#include <iomanip>
#include "Movie.h"

Movie::Movie(std::string title, int runningTime, Money fee, std::shared_ptr<DiscountPolicy> discountPolicy)
    : title(title), runningTime(std::chrono::duration<int>(runningTime)*60), fee(fee), discountPolicy(std::move(discountPolicy)) {}

Money Movie::getFee() {
    return fee;
}

Money Movie::calculateMovieFee(Screening& screening){
    return fee - (*discountPolicy).calculateDiscountAmount(screening);
}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {
    os << "title: " << movie.title << ", runningTime: " << (std::chrono::duration_cast<std::chrono::minutes> (movie.runningTime)).count();
    return os;
}