#include "vector3.h"

#include <cmath>

Vector3& Vector3::operator=(const Vector3 &other)
{
    if (this == &other)
        return *this;
    _x = other._x;
    _y = other._y;
    _z = other._z;
    return *this;
}


double Vector3::Length() const
{
    return std::sqrt(LengthSquared());
}

double Vector3::LengthSquared() const
{
    return _x * _x + _y * _y + _z * _z;
}

Vector3 Vector3::operator*(double scalar) const
{
    return Vector3(_x * scalar, _y * scalar, _z * scalar);
}

Vector3 Vector3::operator/(double scalar) const
{
    return *this * (1.0 / scalar);
}

Vector3 Vector3::operator+(const Vector3& other) const
{
    return Vector3(_x + other._x, _y + other._y, _z + other._z);
}

Vector3 Vector3::operator-(const Vector3& other) const
{
    return *this + (-other);
}

Vector3 Vector3::operator-() const
{
    return Vector3(-_x, -_y, -_z);
}

Vector3& Vector3::operator/=(double t)
{
    return *this = *this / t;
}

Vector3& Vector3::operator+=(const Vector3& other)
{
    return *this = *this + other;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
    return *this = *this - other;
}
