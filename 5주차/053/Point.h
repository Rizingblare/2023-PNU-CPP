#include <cmath>

class Point {
public:
    Point(double x=0, double y=0) : x(x), y(y) {}
    double norm() const {return sqrt(x*x + y*y);};
    double getX() const {return x;}
    double getY() const {return y;}
private:
    const double x, y;
};
