#include "rectangle.h"
#include <algorithm>

Rectangle::Rectangle(const Point& lb, const Point& rt)
    : leftBottom(lb), rightTop(rt) {}

double Rectangle::getArea() const {
    double w = rightTop.x - leftBottom.x;
    double h = rightTop.y - leftBottom.y;
    return w * h;
}

Point Rectangle::getCenter() const {
    return Point((leftBottom.x + rightTop.x) / 2,
                 (leftBottom.y + rightTop.y) / 2);
}

void Rectangle::move(double dx, double dy) {
    leftBottom.x += dx;
    leftBottom.y += dy;
    rightTop.x += dx;
    rightTop.y += dy;
}

void Rectangle::scale(double factor) {
    Point center = getCenter();
    leftBottom.x = center.x + (leftBottom.x - center.x) * factor;
    leftBottom.y = center.y + (leftBottom.y - center.y) * factor;
    rightTop.x = center.x + (rightTop.x - center.x) * factor;
    rightTop.y = center.y + (rightTop.y - center.y) * factor;
}

std::string Rectangle::getName() const {
    return "RECTANGLE";
}
