#include "generation.h"

double gen::generation::transRadiusToRadian(double angle) { // private
    return angle * M_PI / 180.0;
}

Point gen::generation::rotatePoint(const Point& p, double rad) { // private
    double c = std::cos(rad);
    double s = std::sin(rad);

    Point r;

    r.x = p.x * c - p.y * s;
    r.y = p.x * s + p.y * c;

    return r;
}

Point gen::generation::rotatePointBack(const Point& p, double rad) { // private
    return rotatePoint(p, -rad);
}

bool gen::generation::segHorizontal(const Point& p1, const Point& p2, double hy, double &x) { // private
    double y1 = p1.y, y2 = p2.y;

    if ((y1 < hy && y2 < hy) || (y1 > hy && y2 > hy)) return false;


    if (std::abs(y1 - y2) < 1e-12) return false;

    double t = (hy - y1) / (y2 - y1); 
    if (t < -1e-12 || t > 1 + 1e-12) return false;
    x = p1.x + t * (p2.x - p1.x);
    return true;
}

void gen::generation::generateForContour(const std::vector<Point>& contour) { // private
    double rad = transRadiusToRadian(angle_);

    std::vector<Point> rotated;
    rotated.reserve(contour.size());
    for (const auto &p : contour) 
        rotated.push_back( rotatePoint(p, -rad) );

    double minY = std::numeric_limits<double>::infinity();
    double maxY = -std::numeric_limits<double>::infinity();
    for (const auto &p : rotated) {
        if (p.y < minY) minY = p.y;
        if (p.y > maxY) maxY = p.y;
    }

    double startY = std::floor(minY / step_) * step_;

    for (double hy = startY; hy <= maxY + 1e-12; hy += step_) {
        std::vector<double> xs;
        xs.reserve(contour.size());

        for (size_t i = 0; i < rotated.size(); ++i) {
            size_t j = (i + 1) % rotated.size();
            double x;
            if (segHorizontal(rotated[i], rotated[j], hy, x)) {
                xs.push_back(x);
            }
        }

        if (xs.empty()) continue;

        std::sort(xs.begin(), xs.end());

        for (size_t k = 0; k + 1 < xs.size(); k += 2) {
            double x1 = xs[k];
            double x2 = xs[k+1];

            Point p1_rot { x1, hy };
            Point p2_rot { x2, hy };

            Point p1 = rotatePoint(p1_rot, rad);
            Point p2 = rotatePoint(p2_rot, rad);

            lines_.emplace_back(p1, p2);
        }
    }
}

void gen::generation::generate() { // public
    lines_.clear();
    for (const auto &contour : contoursPoints_) 
        generateForContour(contour);
}

std::vector<Line>& gen::generation::getLines() { // public
    return lines_;
}