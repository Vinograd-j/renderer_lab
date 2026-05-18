#include "../include/circle.h"

std::optional<Pixel> Circle::Apply(const Vector2& ndc, float aspectRatio) const
{
    Vector2 correctedPoint(ndc.x() * aspectRatio, ndc.y());
    Vector2 correctedCenter(_center.x() * aspectRatio, _center.y());

    if ((correctedCenter - correctedPoint).LengthSquared() <= _radius * _radius)
        return _colorProvider->GetColor(correctedPoint.x(), correctedPoint.y());

    return std::nullopt;
}