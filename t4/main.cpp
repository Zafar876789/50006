#include "rectangle.h"
#include "circle.h"
#include "compositeshape.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

void printShape(const Shape& shape, int indent = 0) {
    std::cout << std::fixed << std::setprecision(2);
    Point c = shape.getCenter();
    std::cout << "[" << shape.getName() << ", (" << c.x << ", " << c.y << "), " << shape.getArea() << "]";
}

void printComposite(const CompositeShape& comp) {
    std::cout << std::fixed << std::setprecision(2);
    Point c = comp.getCenter();
    std::cout << "[COMPOSITE, (" << c.x << ", " << c.y << "), " << comp.getArea() << ":" << std::endl;
    const auto& shapes = comp.getShapes();
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "  ";
        printShape(*shapes[i]);
        if (i != shapes.size() - 1) std::cout << ",";
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Rectangle>(Point(0, 0), Point(4, 2)));
    
    shapes.push_back(std::make_unique<Circle>(Point(5, 5), 3));
    
    shapes.push_back(std::make_unique<Rectangle>(Point(2, 3), Point(6, 5)));
    
    shapes.push_back(std::make_unique<Circle>(Point(-2, -1), 1.5));
    
    auto composite = std::make_unique<CompositeShape>();
    composite->addShape(std::make_unique<Rectangle>(Point(0, 0), Point(3, 2)));
    composite->addShape(std::make_unique<Circle>(Point(4, 4), 2));
    composite->addShape(std::make_unique<Rectangle>(Point(5, 0), Point(8, 1)));
    shapes.push_back(std::move(composite));

    std::cout << "=== BEFORE SCALING ===" << std::endl;
    for (const auto& s : shapes) {
        if (s->getName() == "COMPOSITE") {
            printComposite(static_cast<const CompositeShape&>(*s));
        } else {
            printShape(*s);
            std::cout << std::endl;
        }
    }

    for (auto& s : shapes) {
        s->scale(2.0);
    }

    std::cout << "\n=== AFTER SCALING (x2) ===" << std::endl;
    for (const auto& s : shapes) {
        if (s->getName() == "COMPOSITE") {
            printComposite(static_cast<const CompositeShape&>(*s));
        } else {
            printShape(*s);
            std::cout << std::endl;
        }
    }

    return 0;
}
