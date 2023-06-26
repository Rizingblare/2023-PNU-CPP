//
// Created by edward on 22. 1. 16..
//
#include "DiscountPolicy.h"

DiscountPolicy::DiscountPolicy(std::vector<std::shared_ptr<DiscountCondition>> conditions)
    : conditions(std::move(conditions)) {}

Money DiscountPolicy::calculateDiscountAmount(Screening& screening){
    for (auto& c : conditions) {
        if ((*c).test(screening)) {
            return getDiscountAmount(screening);
        }
    }
    return Money{0L};
}