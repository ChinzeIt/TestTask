#pragma once

namespace gen {
class generation {
    private:
    double angle_, step_;
    std::vector<std::vector<Point>> contoursPoints_;
    
    public:
    generation (double angle, double step, std::vector<std::vector<Point>> contoursPoints): angle_(angle), step_(step), contoursPoints_(contoursPoints) {}

};
}