#ifndef PARALLELEPIPED_HPP
#define PARALLELEPIPED_HPP

class Parallelepiped
{
private:
    double x;
    double y;
    double z;

public:
    Parallelepiped(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double y);
    double volume() const;
    double area() const;
    double diagonalLength() const;
};

#endif
