//
// Created by Rizingblare on 2023-06-06.
//

#ifndef INC_230308_POLYGON_H
#define INC_230308_POLYGON_H


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Polygon : public IShape {
public:
    Polygon(const vector<Point>& points) : IShape(points) {}
    ~Polygon() { cout << "Polygon destructor called" << endl; }
    double getArea() const override {
        int n = points.size();

        vector<Point> c_points(points.begin(), points.end());
        c_points.push_back(points[0]);

        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++) {
            x += c_points[i].x * c_points[i + 1].y;
            y += c_points[i].y * c_points[i + 1].x;
        }

        return abs(x - y) / 2;
    }

    double getPerimeter() const override {
        int n = points.size();

        vector<Point> c_points(points.begin(), points.end());
        c_points.push_back(points[0]);

        double result = 0;
        for (int i = 0; i < n; i++)
            result += calcDist(c_points[i], c_points[i+1]);

        return result;
    }

protected:
    string toString() const override {
        return "Polygon Area: " + formatDouble(round(this->getArea()*100)/100) + ", Perimeter: " + formatDouble(round(this->getPerimeter()*100)/100);
    }

};


#endif //INC_230308_POLYGON_H
