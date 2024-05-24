#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle
{
private:
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c);
    double getA() const;
    double getB() const;
    double getC() const;
    void setA(double a);
    void setB(double b);
    void setC(double c);
    double perimeter() const;
    double area() const;
};

#endif
