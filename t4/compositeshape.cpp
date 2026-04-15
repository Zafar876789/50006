#include "compositeshape.h"
#include <algorithm>
#include <limits>

void CompositeShape::addShape(std::unique_ptr<Shape> shape) {
    shapes.push_back(std::move(shape));
}

double CompositeShape::getArea() const {
    double total = 0;
    for (const auto& s : shapes) {
        total += s->getArea();
    }
    return total;
}

Point CompositeShape::getCenter() const {
    if (shapes.empty()) return Point(0, 0);
    double minX = std::numeric_limits<double>::max();
    double minY = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::lowest();
    double maxY = std::numeric_limits<double>::lowest();
    
    for (const auto& s : shapes) {
        Point c = s->getCenter();
        minX = std::min(minX, c.x);
        minY = std::min(minY, c.y);
        maxX = std::max(maxX, c.x);
        maxY = std::max(maxY, c.y);
    }
    return Point((minX + maxX) / 2, (minY + maxY) / 2);
}

void CompositeShape::move(double dx, double dy) {
    for (auto& s : shapes) {
        s->move(dx, dy);
    }
}

void CompositeShape::scale(double factor) {
    Point center = getCenter();
    for (auto& s : shapes) {
        Point c = s->getCenter();
        double dx = c.x - center.x;
        double dy = c.y - center.y;
        s->move(dx * (factor - 1), dy * (factor - 1));
        s->scale(factor);
    }
}

std::string CompositeShape::getName() const {
    return "COMPOSITE";
}

const std::vector<std::unique_ptr<Shape>>& CompositeShape::getShapes() const {
    return shapes;
}
