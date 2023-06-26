//
// Created by Rizingblare on 2023-06-05.
//

#ifndef INC_230308_RECTANGLE_H
#define INC_230308_RECTANGLE_H

#include <iostream>
#include <vector>
#include <string>

#include "Helper.h"

using namespace std;

std::string formatDouble(double value) {
    std::string str = std::to_string(value);
    size_t dotPos = str.find('.');
    if (dotPos != std::string::npos && str.length() > dotPos + 2) {
        str = str.substr(0, dotPos + 3);
    }
    return str;
}

class Rectangle : public IShape {
public:
    Rectangle(const vector<Point>& points) : IShape(points) {}
    ~Rectangle() { cout << "Rectangle destructor called" << endl; }
    double getArea() const override {
        double height = calcDist(points[0], points[1]);
        double width = calcDist(points[0], points[3]);

        return height * width;
    }

    double getPerimeter() const override {
        double height = calcDist(points[0], points[1]);
        double width = calcDist(points[0], points[3]);

        return 2 * (height * width);
    }

protected:
    string toString() const override {
        return "Rectangle Area: " + formatDouble(round(this->getArea()*100)/100) + ", Perimeter: " + formatDouble(this->getPerimeter());
    }

};

#endif //INC_230308_RECTANGLE_H
