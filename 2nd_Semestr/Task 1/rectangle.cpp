#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(double x, double y) : x(x), y(y) {}

double Rectangle::getX() const {
    return x;
}
double Rectangle::getY() const {
    return y;
}


void Rectangle::setX(double x) {
    this->x = x;
}

void Rectangle::setY(double y) {
    this->y = y;
}

double Rectangle::area() const {
    return x * y;
}

double Rectangle::perimeter() const {
    return 2 * x + 2 * y;
}

double Rectangle::diagonalLength() const {
    return std::sqrt(x*x+y*y);
}
