#include "out.h"

void outs::out::printRes(std::vector<Line> lines) { // public
    std::cout << "Generated " << lines.size() << " lines\n";
    for (size_t i = 0; i < lines.size(); ++i) {
        const auto &L = lines[i];
        std::cout << i << ": [" << L.a.x << "; " << L.a.y << "] & [" << L.b.x << "; " << L.b.y << "]\n";
    }
}