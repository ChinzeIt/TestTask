#pragma once

#include "struct.h"

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

namespace gen {
class generation {
    private:
    double angle_, step_;
    std::vector<std::vector<Point>> contoursPoints_;
    std::vector<Line> lines_;

    double transRadiusToRadian(double angle);
    Point rotatePoint(const Point& p, double rad);
    Point rotatePointBack(const Point& p, double rad);
    bool segHorizontal(const Point& p1, const Point& p2, double hy, double &x);
    void generateForContour(const std::vector<Point>& contour);

    public:
    generation (double angle, double step, std::vector<std::vector<Point>> contoursPoints): angle_(angle), step_(step), contoursPoints_(contoursPoints) {}
    void generate ();
    std::vector<Line>& getLines();
};
}