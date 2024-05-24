#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
private:
    double radius;

public:
    Sphere(double radius);
    double getRadius() const;
    void setRadius(double radius);
    double area() const;
    double volume() const;
};

#endif 