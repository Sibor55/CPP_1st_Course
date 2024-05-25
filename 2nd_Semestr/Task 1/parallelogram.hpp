#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

class Parallelogram
{
private:
    double x;
    double y;
    double alpha;

public:
    Parallelogram(double x, double y, double alpha);
    double getA() const;
    double getX() const;
    double getY() const;
    void setA(double alpha);
    void setX(double x);
    void setY(double y);
    double area() const;
    double perimeter() const;

};

#endif
