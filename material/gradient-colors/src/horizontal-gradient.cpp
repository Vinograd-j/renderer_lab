#include "../include/horizontal-gradient.h"

#include <cmath>

Pixel HorizontalGradient::GetColor(float nx, float ny) const
{
    double t = (nx + 1.0) * 0.5;

    t = std::pow(t, 2);

    return Pixel(
        GetStartColor().r * (1 - t) + GetEndColor().r * t,
        GetStartColor().g * (1 - t) + GetEndColor().g * t,
        GetStartColor().b * (1 - t) + GetEndColor().b * t
    );
}
