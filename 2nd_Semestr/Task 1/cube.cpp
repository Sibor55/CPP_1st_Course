#include "cube.hpp"
#include <cmath>

Cube::Cube(double side) : side(side) {}

double Cube::getSide() const {
    return side;
}

void Cube::setSide(double side) {
    this->side = side;
}

double Cube::volume() const {
    return side*side*side;
}

double Cube::perimeter() const {
    return 12*side;
}

double Cube::diagonalLength() const {
    return std::sqrt(3)*side;
}
