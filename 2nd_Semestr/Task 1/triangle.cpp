#include "triangle.hpp"
#include <cmath>

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

double Triangle::getA() const
{
    return a;
}
double Triangle::getB() const
{
    return b;
}

void Triangle::setA(double a)
{
    this->a = a;
}

void Triangle::setB(double b)
{
    this->b = b;
}

void Triangle::setC(double c)
{
    this->c = c;
}

double Triangle::perimeter() const
{
    return a + b + c;
}

double Triangle::area() const
{
    double p = (a + b + c) / 2.f;
    return std::sqrt(p * (p - a) * (p - b) * (p - c))
}
