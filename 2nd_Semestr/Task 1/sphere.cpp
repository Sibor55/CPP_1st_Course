#include "sphere.hpp"
#include <cmath>

Sphere::Sphere(double radius) : radius(radius) {}

double Sphere::getRadius() const
{
    return radius;
}

void Sphere::setRadius(double radius)
{
    this->radius = radius;
}

double Sphere::area() const
{
   return M_PI * 4 * radius * radius;
}

double Sphere::volume() const
{
    return 4.f/3.f * M_PI * radius * radius * radius;
}