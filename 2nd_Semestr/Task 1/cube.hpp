#ifndef CUBE_HPP
#define CUBE_HPP

class Cube {
private:
    double side;

public:
    Cube(double side);
    double getSide() const;
    void setSide(double side);
    double volume() const;
    double perimeter() const;
    double diagonalLength() const;
};

#endif 
