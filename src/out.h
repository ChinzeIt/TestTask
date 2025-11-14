#pragma once

/** @file out.h
* @brief Заголовок для класса Out — вывод результата.
*/


/** @class Out
* @brief Класс для печати/экспорта сгенерированных линий.
*
* Основной метод:
* - void printRes(const std::vector<Line>& lines)
* - @brief Печатает результат в текстовом виде (координаты каждой линии).
*/

#include "struct.h"

#include <iostream>
#include <vector>

namespace outs {
class out {
    public:
    static void printRes(std::vector<Line> lines);
};
}