//
// Created by edward on 22. 1. 16..
//

#include <iostream>
#include "Screening.h"
#include "PeriodCondition.h"

PeriodCondition::PeriodCondition(DayOfWeek dayOfWeek, std::tm startTime, std::tm endTime)
    : dayOfWeek(dayOfWeek), startTime(startTime), endTime(endTime) {}

bool PeriodCondition::test(Screening& screening) {
    std::tm movieTime = screening.getStartTime();
    std::time_t movieStartTime = std::mktime(&movieTime);
    return movieTime.tm_wday == dayOfWeek &&
        (std::mktime(&startTime) < movieStartTime) &&
        (movieStartTime < std::mktime(&endTime));
}

