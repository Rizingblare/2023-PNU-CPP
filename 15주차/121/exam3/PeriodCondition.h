//
// Created by edward on 22. 1. 12..
//

#ifndef WEEK11_PERIODCONDITION_H
#define WEEK11_PERIODCONDITION_H

#include "DiscountCondition.h"

enum DayOfWeek {SUN=0, MON, TUE, WEN, THU, FRI, SAT};                                 \
class PeriodCondition : public DiscountCondition {
public:
    PeriodCondition(DayOfWeek dayOfWeek, std::tm startTime, std::tm endTime);
    bool test(Screening& screening) override;
    virtual ~PeriodCondition() noexcept {}
private:
    DayOfWeek dayOfWeek;
    std::tm startTime;
    std::tm endTime;
};

#endif //WEEK11_PERIODCONDITION_H
