#include "parser.h"

bool pars::parser::checkFlag (char** argv) { // private
    std::string buff1(argv[1]);
    std::string buff2(argv[3]);
    if (buff1!="--angle" || buff2!="--step") return false;
    return true;
}

bool pars::parser::checkNum (char* num) { // private
    if (num[0]=='.') return false;

    for (int i=0; num[i]!='\0'; ++i) {
        if (num[i]=='.') continue;
        if (num[i]<'0' || num[i]>'9') return false;
    }

    return true;
}

bool pars::parser::input (int argc, char** argv) { // public
    if (argc!=5) return false;
    if (!checkFlag(argv) || !checkNum(argv[2]) || !checkNum(argv[4])) return false;

    return true;
}

bool pars::parser::massive () { // public
    while (true) {
        std::vector<Point> current;
        
        for (int i = 0; i < 4; ++i) {
            std::string line;
            
            if (!std::getline(std::cin, line))
                return false;
            
            std::istringstream iss(line);
            Point point;
            if (iss >> point.x >> point.y) {
                current.push_back(point);
            } else {
                std::cout << "Format: *num* *num*" << '\n';
                i--;
                continue;
            }
        }

        contoursPoints.push_back(current);

        std::cout << "Add new figure?" << "\n";
        std::string answer;

        if (!std::getline(std::cin, answer)) return false;

        if (answer=="no" || answer=="n") break;
    }

    return true;
}

std::vector<std::vector<Point>> pars::parser::getPoints() {
    return contoursPoints;
}