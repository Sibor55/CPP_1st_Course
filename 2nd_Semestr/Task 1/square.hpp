#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square
{
private:
    double side;

public:
    Square(double side);
    double getSide() const;
    void setSide(double side);
    double area() const;
    double perimeter() const;
    double diagonalLength() const;
};

#endif
