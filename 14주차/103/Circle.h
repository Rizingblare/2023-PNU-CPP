//
// Created by Rizingblare on 2023-06-05.
//

#ifndef INC_230308_CIRCLE_H
#define INC_230308_CIRCLE_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Circle: public IShape {
    Point point;
    double radius;
public:
    Circle(const Point& point, int radius) : point(point), radius(radius) {}
    ~Circle() { cout << "Circle destructor called" << endl; }
    double getArea() const override {
        return radius * radius * M_PI;
    }

    double getPerimeter() const override {
        return 2 * radius * M_PI;
    }

protected:
    string toString() const override {
        return "Circle Area: " + formatDouble(round(this->getArea()*100)/100) + ", Perimeter: " + formatDouble(round(this->getPerimeter()*100)/100);
    }

};

#endif //INC_230308_CIRCLE_H
