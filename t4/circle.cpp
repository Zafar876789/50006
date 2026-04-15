#include "circle.h"
#include <cmath>

Circle::Circle(const Point& c, double r) : center(c), radius(r) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

Point Circle::getCenter() const {
    return center;
}

void Circle::move(double dx, double dy) {
    center.x += dx;
    center.y += dy;
}

void Circle::scale(double factor) {
    radius *= factor;
}

std::string Circle::getName() const {
    return "CIRCLE";
}
