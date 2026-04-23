#pragma once

class Vector3
{

private:

    double _x, _y, _z;

public:

    explicit Vector3(const double x, const double y, const double z) : _x(x), _y(y), _z(z) { }

    Vector3(const Vector3& other) = default;

    Vector3(Vector3&& other) noexcept = default;

    Vector3& operator=(const Vector3& other);

    Vector3& operator=(Vector3&& other) noexcept = default;

public:

    double x() const { return _x; }

    double y() const { return _y; }

    double z() const { return _z; }

public:

    double Length() const;

    double LengthSquared() const;

public:

    Vector3 operator*(double scalar) const;

    Vector3 operator/(double scalar) const;

    Vector3 operator+(const Vector3& other) const;

    Vector3 operator-(const Vector3& other) const;
    Vector3 operator-() const;

public:

    Vector3& operator/=(double t);

    Vector3& operator+=(const Vector3& other);

    Vector3& operator-=(const Vector3& other);

};

inline double Dot(const Vector3& first, const Vector3& second)
{
    return first.x() * second.x() + first.y() * second.y() + first.z() * second.z();
}

inline Vector3 Cross(const Vector3& f, const Vector3& s)
{
    return Vector3(
                    f.y() * s.z() - s.y() * f.z(),
                    s.x() * f.z() - f.x() * s.z(),
                    f.x() * s.y() - s.x() * f.y()
                  );
}

inline Vector3 Normalize(const Vector3& vec)
{
    return vec / vec.Length();
}

inline Vector3 operator*(double scalar, const Vector3& v)
{
    return v * scalar;
}