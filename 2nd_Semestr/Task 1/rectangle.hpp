#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
private:
    double x;
    double y;

public:
    Rectangle(double x, double y);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    double area() const;
    double perimeter() const;
    double diagonalLength() const;
};

#endif 
