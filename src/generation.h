#pragma once

/** @file generation.h
* @brief Заголовок для класса Generation — генерация штриховки внутри контуров.
*/


/** @class Generation
* @brief Генерирует линии штриховки внутри заданных контуров.
*
* Вспомогательные private методы:
* - double transRadiusToRadian(double deg)
* - @brief Переводит градусы в радианы.
*
* - Point rotatePoint(const Point& p, double rad)
* - @brief Поворачивает точку (или фигуру) на угол rad (в радианах).
*
* - Point rotatePointBack(const Point& p, double rad)
* - @brief Возвращает точку к исходному положению (обратный поворот).
*
* - bool segHorizontal(const Point& p1, const Point& p2, double hy, double &x)
* - @brief Проверяет пересечение ребра (p1->p2) с горизонтальной линией y = hy.
* - @return true и записывает x, если пересечение есть (учитывая полуоткрытое правило).
*
* - void generateForContour(const std::vector<Point>& contour)
* - @brief Для одного контура: поворачивает контур, ищет minY/maxY, шаг за шагом
* идёт по высоте, находит пересечения, формирует пары отрезков, поворачивает
* их обратно и сохраняет в список lines_.
*
* Основной публичный метод:
* - void generate()
* - @brief Запускает процесс генерации штриховки по всем контурам.
*
* - const std::vector<Line>& getLines() const
* - @brief Возвращает список сгенерированных линий (отрезков).
*/

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

    double transRadiusToRadian(double angle); /**< Градусы -> радианы */
    Point rotatePoint(const Point& p, double rad); /**< Поворот точки */
    Point rotatePointBack(const Point& p, double rad); /**< Обратный поворот */
    bool segHorizontal(const Point& p1, const Point& p2, double hy, double &x); /**< Пересечение */
    void generateForContour(const std::vector<Point>& contour); /**< Генерация для одного контура */

    public:
    generation (double angle, double step, std::vector<std::vector<Point>> contoursPoints): angle_(angle), step_(step), contoursPoints_(contoursPoints) {}
    void generate (); /**< Выполняет генерацию для всех контуров */
    std::vector<Line>& getLines(); /**< Получить сгенерированные линии */
};
}