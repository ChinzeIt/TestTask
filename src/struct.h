#pragma once

/** @file struct.h
* @brief Структуры данных, используемые в проекте.
*/


/** @struct Point
* @brief Структура для хранения 2D-точки.
*
* Поля:
* - double x — координата X
* - double y — координата Y
*/
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