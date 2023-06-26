//
// Created by Rizingblare on 2023-06-05.
//

#ifndef INC_230308_TRIANGLE_H
#define INC_230308_TRIANGLE_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Triangle : public IShape {
public:
    Triangle(const vector<Point>& points) : IShape(points) {}
    ~Triangle() { cout << "Triangle destructor called" << endl; }
    double getArea() const override {
        return abs((points[0].x * points[1].y) + (points[1].x * points[2].y) + (points[2].x * points[0].y)
        - (points[1].x * points[0].y) + (points[2].x * points[1].y) + (points[0].x * points[2].y)) / 2;
    }

    double getPerimeter() const override {
        return calcDist(points[0], points[1]) + calcDist(points[1], points[2]) + calcDist(points[2], points[0]);
    }

protected:
    string toString() const override {
        return "Triangle Area: " + formatDouble(this->getArea()) + ", Perimeter: " + formatDouble(round(this->getPerimeter()*100)/100);
    }

};

#endif //INC_230308_TRIANGLE_H
