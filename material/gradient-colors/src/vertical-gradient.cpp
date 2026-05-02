#include "../include/vertical-gradient.h"

#include <cmath>

Pixel VerticalGradient::GetColor(float nx, float ny) const
{
    double t = (ny + 1.0) * 0.5;

    t = std::pow(t, 1.6);

    return Pixel(
        GetStartColor().r * (1 - t) + GetEndColor().r * t,
        GetStartColor().g * (1 - t) + GetEndColor().g * t,
        GetStartColor().b * (1 - t) + GetEndColor().b * t
    );
}