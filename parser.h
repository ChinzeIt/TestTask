#pragma once

#include "struct.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

namespace pars {
class parser {
    private:
    bool checkFlag(char** argv);
    bool checkNum(char* num);

    std::vector<std::vector<Point>> contoursPoints;

    public:
    bool input (int argc, char** argv);
    bool massive ();
    std::vector<std::vector<Point>> getPoints();
};
}