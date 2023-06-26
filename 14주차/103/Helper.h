//
// Created by Rizingblare on 2023-06-05.
//

#ifndef INC_230308_HELPER_H
#define INC_230308_HELPER_H

#include <cmath>
#include <iostream>
#include "IShape.h"

using namespace std;

double calcDist(const Point& p1, const Point& p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    return std::sqrt(dx*dx + dy*dy);
}

#endif //INC_230308_HELPER_H
