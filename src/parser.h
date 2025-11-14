#pragma once

/** @file parser.h
* @brief Заголовок для класса Parser — обработка аргументов и ввод контуров.
*/


/** @class Parser
* @brief Обрабатывает командную строку и ввод точек контуров.
*
* Основные методы:
* - bool input(int argc, char** argv)
* - @brief Проверяет аргументы командной строки (--angle и --step).
* - @param argc Количество аргументов
* - @param argv Массив аргументов
* - @return true при корректных аргументах, иначе false
*
* - bool massive()
* - @brief Считывает контуры из стандартного ввода. Каждый контур — 4 точки (x y).
* - @return true при успешном вводе хотя бы одного контура, иначе false
*
* - std::vector<std::vector<Point>> getPoints()
* - @brief Возвращает считанные контуры (вектор контуров).
*/

#include "struct.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

namespace pars {
class parser {
    private:
    bool checkFlag(char** argv); /**< Внутренняя проверка флагов */
    bool checkNum(char* num); /**< Внутренняя проверка, что аргумент — число */

    std::vector<std::vector<Point>> contoursPoints;

    public:
    bool input (int argc, char** argv); /**< Проверяет argc/argv */
    bool massive (); /**< Считывает контуры из stdin */
    std::vector<std::vector<Point>> getPoints(); /**< Получить считанные контуры */
}; 
}