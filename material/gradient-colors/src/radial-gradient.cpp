#include "../include/radial-gradient.h"

#include <cmath>

Pixel RadialGradient::GetColor(int x, int y) const
{
    double dx = x - _center.x();
    double dy = y - _center.y();

    double dist = std::sqrt(dx * dx + dy * dy);

    double t = dist / _radius;
    if (t > 1.0f) t = 1.0f;

    t = t * t * (3.0f - 2.0f * t);
    t = t * t;

    return Pixel(
        GetStartColor().r * (1 - t) + GetEndColor().r * t,
        GetStartColor().g * (1 - t) + GetEndColor().g * t,
        GetStartColor().b * (1 - t) + GetEndColor().b * t
    );
}
