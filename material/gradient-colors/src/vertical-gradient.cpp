#include "../include/vertical-gradient.h"

#include <cmath>

Pixel VerticalGradient::GetColor(float nx, float ny) const
{
    double t = static_cast<double>(ny) / (_imageHeight - 1);

    t = t * t * (3.0 - 2.0 * t);

    t = std::pow(t, 1.6);

    return Pixel(
        GetStartColor().r * (1 - t) + GetEndColor().r * t,
        GetStartColor().g * (1 - t) + GetEndColor().g * t,
        GetStartColor().b * (1 - t) + GetEndColor().b * t
    );
}