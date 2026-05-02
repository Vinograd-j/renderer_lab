#include "../include/radial-gradient.h"

Pixel RadialGradient::GetColor(float nx, float ny) const
{
    double dx = nx - _center.x();
    double dy = ny - _center.y();

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
