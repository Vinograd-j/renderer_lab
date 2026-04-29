#include "../include/vertical-gradient.h"

#include <cmath>

Pixel VerticalGradient::GetColor(int x, int y) const
{
    double t = static_cast<double>(y) / (GetAxisSize() - 1);
    t = std::pow(t, 2);

    return Pixel(
        GetStartColor().r * (1 - t) + GetEndColor().r * t,
        GetStartColor().g * (1 - t) + GetEndColor().g * t,
        GetStartColor().b * (1 - t) + GetEndColor().b * t
    );
}
