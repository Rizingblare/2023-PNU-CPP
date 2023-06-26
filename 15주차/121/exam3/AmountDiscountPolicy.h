//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_AMOUNTDISCOUNTPOLICY_H
#define WEEK11_AMOUNTDISCOUNTPOLICY_H

#include <vector>

#include "DiscountPolicy.h"

class AmountDiscountPolicy : public DiscountPolicy {
public:
    AmountDiscountPolicy(Money discountAmount, std::vector<std::shared_ptr<DiscountCondition>> conditions);
    virtual ~AmountDiscountPolicy() noexcept {}
protected:
    Money getDiscountAmount(Screening& screening) override ;
private:
    Money discountAmount;
};
#endif //WEEK11_AMOUNTDISCOUNTPOLICY_H
