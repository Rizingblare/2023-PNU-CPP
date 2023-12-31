//
// Created by Rizingblare on 2023-06-05.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

#include "IShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"

using namespace std;

void doingSomething(const vector<unique_ptr<IShape>>& shapes) {
    for (const auto& s : shapes)
    cout << *s << endl;

    double totalArea = accumulate(shapes.cbegin(), shapes.cend(), 0.0,
                                  [](double cur_sum, const auto& rhs){
                                      return cur_sum + (*rhs).getArea();
                                  });

    double totalPerimeter = accumulate(shapes.cbegin(), shapes.cend(), 0.0,
                                       [](double cur_sum, const auto& rhs){
                                           return cur_sum + (*rhs).getPerimeter();
                                       });
    cout << std::fixed << std::setprecision(2);
    cout << "totalArea: " << totalArea << ", " << "totalPerimeter: " << totalPerimeter << endl;
}


int main() {
    std::vector<std::unique_ptr<IShape>> shapes;

    shapes.emplace_back(std::make_unique<Rectangle>(std::vector<Point>{{0, 0}, {0, 2}, {2, 2}, {2, 0}}));
    shapes.emplace_back(std::make_unique<Triangle>(std::vector<Point>{{0, 0}, {0, 2}, {2, 2}}));
    shapes.emplace_back(std::make_unique<Circle>(Point{0, 0}, 3));
    shapes.emplace_back(std::make_unique<Polygon>(std::vector<Point>{{0, 0}, {0, 2}, {2, 2}, {2, 0}, {1, 1}}));

    doingSomething(shapes);

    return 0;
}