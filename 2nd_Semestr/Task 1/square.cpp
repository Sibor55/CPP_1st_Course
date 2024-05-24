#include "square.hpp"
#include <cmath>

Square::Square(double side) : side(side) {}

double Square::getSide() const
{
    return side;
}

void Square::setSide(double side)
{
    this->side = side;
}

double Square::area() const
{
    return side * side;
}

double Square::perimeter() const
{
    return 4 * side;
}

double Square::diagonalLength() const
{
    return std::sqrt(2) * side;
}
