//
// Created by edward on 22. 1. 12..
//
#include <chrono>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include "Money.h"
#include "Movie.h"
#include "AmountDiscountPolicy.h"
#include "SequenceCondition.h"
#include "PeriodCondition.h"
#include "Customer.h"
#include "Screening.h"

time_t create_movie_time(int min, int hour, int day, int mon, int year) {
    tm whenScreened {0, min, hour, // second, minute, hour
                     day, mon-1, year - 1900 }; // 1-based day, 0-based month, year since 1900
    time_t t = mktime(&whenScreened);
    return t;
}

std::tm make_time(const char* time_str){
    std::tm start_tm { 0, 30, 12, // second, minute, hour
                       13, 0, 2022 - 1900 };
    std::istringstream st(time_str);
    st >> std::get_time(&start_tm, "%H:%M"); // or just %T in this case
    //std::cout << std::put_time(&start_tm, "%H:%M") << std::endl;
    //std::time_t time = std::mktime(&start_tm);
    //std::tm* local_time = std::localtime(&time);
    //std::cout << std::put_time(local_time, "%H:%M") << std::endl;
    //return std::mktime(&start_tm);
    return start_tm;
}

//std::tm start_time = make_time("12:00");
//std::tm end_time = make_time("18:00");

int main() {
    using namespace std::string_literals;
    typedef std::shared_ptr<DiscountCondition> DiscountConditionPtr;
    typedef std::shared_ptr<DiscountPolicy> DiscountPolicyPtr;

    //DiscountConditionPtr condition1 = std::make_shared<SequenceCondition>(1);
    DiscountConditionPtr condition2 = std::make_shared<PeriodCondition>(DayOfWeek::THU, make_time("12:00"), make_time("18:00"));
    std::vector<DiscountConditionPtr> conditions {condition2};

    DiscountPolicyPtr policy = std::make_shared<AmountDiscountPolicy>(Money{2'000L}, conditions);
    Movie movie {"Doom"s, 120, Money(10'000L), policy};

    time_t t = create_movie_time(30, 12, 13, 1, 2022);
    std::shared_ptr<Screening> screening = std::make_shared<Screening>(movie, 2, *std::localtime(&t));
    std::cout << movie.calculateMovieFee(*screening) << std::endl;

    Customer customer{1, "Kim"};
    auto reservation = (*screening).reserve(customer, 2);
    std::cout << reservation << std::endl;
}


