//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_MOVIE_H
#define WEEK11_MOVIE_H

#include <chrono>
#include <memory>
#include <string>
#include <ostream>

#include "DiscountPolicy.h"

class Movie {
public:
    Movie(std::string title, int runningTime, Money fee, std::shared_ptr<DiscountPolicy> discountPolicy);
    Money getFee();
    Money calculateMovieFee(Screening& screening);
    friend std::ostream &operator<<(std::ostream &os, const Movie &movie);

private:
    std::string title;
    std::chrono::duration<int> runningTime;
    std::shared_ptr<DiscountPolicy> discountPolicy;
    Money fee;
};

#endif //WEEK11_MOVIE_H
