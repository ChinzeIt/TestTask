#pragma once

struct Point {
    double x;
    double y;
};

struct Line {
    Point a;
    Point b;
    Line() {}
    Line(const Point& _a, const Point& _b) : a(_a), b(_b) {}
};