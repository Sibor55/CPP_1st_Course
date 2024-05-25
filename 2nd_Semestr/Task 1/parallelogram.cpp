#include "parallelogram.hpp"
#include <cmath>

Parallelogram::Parallelogram(double x, double y, double alpha) : x(x), y(y), alpha(alpha) {}

double Parallelogram::getA() const {
    return alpha;
}

double Parallelogram::getX() const {
    return x;
}
double Parallelogram::getY() const {
    return y;
}

void Parallelogram::setA(double alpha) {
    this->alpha = alpha;
}
void Parallelogram::setX(double x) {
    this->x = x;
}

void Parallelogram::setY(double y) {
    this->y = y;
}

double Parallelogram::area() const {
    return x * y * std::sin(alpha);
}

double Parallelogram::perimeter() const {
    return 2 * x + 2 * y;
}

