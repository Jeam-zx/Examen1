#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <cmath>

class Vector3D {
private:
    double x;
    double y;
    double z;
public:
    // Constructor
    Vector3D(double x, double y, double z);

    // Operadores sobrecargados +, -, *, %, &, * (escalar)
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(const Vector3D& other) const;
    double operator%(const Vector3D& other) const;
    double operator&() const;

    // Operadores sobrecargados +, -, * (operados con un escalar)
    Vector3D operator*(double scalar) const;
    Vector3D operator+(double scalar) const;
    Vector3D operator-(double scalar) const;

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;
};

#endif  // VECTOR3D_HPP