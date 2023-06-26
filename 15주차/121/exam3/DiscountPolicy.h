//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_DISCOUNTPOLICY_H
#define WEEK11_DISCOUNTPOLICY_H

#include <memory>
#include <vector>

#include "DiscountCondition.h"
#include "Money.h"

class DiscountPolicy {
public:
    DiscountPolicy(std::vector<std::shared_ptr<DiscountCondition>> conditions);
    Money calculateDiscountAmount(Screening& screening);
    virtual ~DiscountPolicy() noexcept {}
protected:
    virtual Money getDiscountAmount(Screening& screening) = 0;
private:
    std::vector<std::shared_ptr<DiscountCondition>> conditions;
};

#endif //WEEK11_DISCOUNTPOLICY_H
