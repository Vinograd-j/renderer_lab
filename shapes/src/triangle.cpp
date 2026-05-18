#include "../include/triangle.h"

#include <algorithm>
#include <cmath>
#include <optional>

#include "../../math/include/vector3.h"

void Triangle::Apply(const Context* context) const
{
    const Image* image = context->GetImage();

    int minX = std::floor(std::min({_a.x(), _b.x(), _c.x()}));
    int maxX = std::ceil(std::max({_a.x(), _b.x(), _c.x()}));
    int minY = std::floor(std::min({_a.y(), _b.y(), _c.y()}));
    int maxY = std::ceil(std::max({_a.y(), _b.y(), _c.y()}));

    minX = std::clamp(minX, 0, image->GetWidth() - 1);
    maxX = std::clamp(maxX, 0, image->GetWidth() - 1);
    minY = std::clamp(minY, 0, image->GetHeight() - 1);
    maxY = std::clamp(maxY, 0, image->GetHeight() - 1);

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {

            auto ab = _b - _a;
            auto ac = _c - _a;
            auto pa = _a - Vector2(x, y);

            auto crossed = Cross(Vector3(ab.x(), ac.x(), pa.x()), Vector3(ab.y(), ac.y(), pa.y()));

            if (std::abs(crossed.z()) < 1e-8)
                return;

            auto uv1 = crossed / crossed.z();

            auto f = 1 - uv1.x() - uv1.y();
            auto u = uv1.x();
            auto v = uv1.y();

            if (f >= 0 && u >= 0 && v >= 0)
                image->SetPixel(x, y, _colorProvider->GetColor(x, y));
        }
    }
}
