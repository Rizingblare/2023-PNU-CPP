//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_DISCOUNTCONDITION_H
#define WEEK11_DISCOUNTCONDITION_H


class Screening;

class DiscountCondition {
public:
    virtual bool test(Screening& screening) = 0;
    virtual ~DiscountCondition() noexcept {}
};

#endif //WEEK11_DISCOUNTCONDITION_H
