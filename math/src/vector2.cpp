#include "../include/vector2.h"

#include <cmath>

Vector2& Vector2::operator=(const Vector2 &other)
{
    if (this == &other)
        return *this;
    _x = other._x;
    _y = other._y;
    return *this;
}

Vector2& Vector2::operator=(Vector2 &&other) noexcept
{
    if (this == &other)
        return *this;
    _x = other._x;
    _y = other._y;
    return *this;
}

double Vector2::Length() const
{
    return std::sqrt(LengthSquared());
}

double Vector2::LengthSquared() const
{
    return _x * _x + _y * _y;
}

Vector2 Vector2::operator*(double scalar) const
{
    return Vector2(_x * scalar, _y * scalar);
}

Vector2 Vector2::operator/(double scalar) const
{
    return *this * (1.0 / scalar);
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(_x + other._x, _y + other._y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return *this + (-other);
}

Vector2 Vector2::operator-() const
{
    return Vector2(-_x, -_y);
}

Vector2& Vector2::operator/=(double t)
{
    return *this = *this / t;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    return *this = *this + other;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    return *this = *this - other;
}
