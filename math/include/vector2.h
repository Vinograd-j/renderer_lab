#pragma once

class Vector2
{

private:

    double _x, _y;

public:

    explicit Vector2(const double x, const double y) : _x(x), _y(y) { }

    Vector2(const Vector2& other) = default;

    Vector2(Vector2&& other) noexcept : _x(other._x), _y(other._y) { }

    Vector2& operator=(const Vector2& other);

    Vector2& operator=(Vector2&& other) noexcept;

public:

    double x() const { return _x; }

    double y() const { return _y; }

public:

    double Length() const;

    double LengthSquared() const;

public:

    Vector2 operator*(double scalar) const;

    Vector2 operator/(double scalar) const;

    Vector2 operator+(const Vector2& other) const;

    Vector2 operator-(const Vector2& other) const;
    Vector2 operator-() const;

public:

    Vector2& operator/=(double t);

    Vector2& operator+=(const Vector2& other);

    Vector2& operator-=(const Vector2& other);

};

inline double Dot(const Vector2& first, const Vector2& second)
{
    return first.x() * second.x() + first.y() * second.y();
}

inline Vector2 Normalize(const Vector2& vec)
{
    return vec / vec.Length();
}