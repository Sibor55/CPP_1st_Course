#include "parallelepiped.hpp"
#include <cmath>

Parallelepiped::Parallelepiped(double x, double y, double z) : x(x), y(y), z(z) {}

double Parallelepiped::getX() const
{
    return x;
}
double Parallelepiped::getY() const
{
    return y;
}

void Parallelepiped::setX(double x)
{
    this->x = x;
}

void Parallelepiped::setY(double y)
{
    this->y = y;
}

void Parallelepiped::setZ(double z)
{
    this->z = z;
}

double Parallelepiped::volume() const
{
    return x * y * z;
}

double Parallelepiped::area() const
{
    return 2 * (z * x + x * y + y * z);
}

double Parallelepiped::diagonalLength() const
{
    return std::sqrt(x * x + y * y) + z * z;
}
