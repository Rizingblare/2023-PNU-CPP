#include "Point.h"

class Rectangle {
public:
    Rectangle(double, double, double, double);
    double area() {
        double width = abs(rightBottom.getX() - leftTop.getX());
        double height = abs(rightBottom.getY() - leftTop.getY());
        return width * height;
    };
private:
    Point leftTop, rightBottom;
};

Rectangle::Rectangle(double x1, double y1, double x2, double y2) : leftTop(x1,y2), rightBottom(x2, y1) {}