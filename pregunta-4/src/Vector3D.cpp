#include "../headers//Vector3D.hpp"

// Constructor
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

// Getters
double Vector3D::getX() const {
    return x;
}

double Vector3D::getY() const {
    return y;
}

double Vector3D::getZ() const {
    return z;
}

// Operador de suma
Vector3D Vector3D::operator+(const Vector3D& vector2) const {
    return Vector3D(x + vector2.getX(), y + vector2.getY(), z + vector2.getZ());
}

// Operador de suma con un escalar
Vector3D Vector3D::operator+(double scalar) const {
    return Vector3D(x + scalar, y + scalar, z + scalar);
}

// Operador de resta
Vector3D Vector3D::operator-(const Vector3D& vector2) const {
    return Vector3D(x - vector2.getX(), y - vector2.getY(), z - vector2.getZ());
}

// Operador de resta con un escalar
Vector3D Vector3D::operator-(double scalar) const {
    return Vector3D(x - scalar, y - scalar, z - scalar);
}


// Operador de producto vectorial
Vector3D Vector3D::operator*(const Vector3D& vector2) const {
    return Vector3D(y * vector2.getZ() - z * vector2.getY(),
                    z * vector2.getX() - x * vector2.getZ(),
                    x * vector2.getY() - y * vector2.getX());
}

// Operador de producto con un escalar
Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(x * scalar, y * scalar, z * scalar);
}

// Operador de producto escalar
double Vector3D::operator%(const Vector3D& vector2) const {
    return x * vector2.getX() + y * vector2.getY() + z * vector2.getZ();
}

// Operador norma
double Vector3D::operator&() const {
    return sqrt(x * x + y * y + z * z);
}


