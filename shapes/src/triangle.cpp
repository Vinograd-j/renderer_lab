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

    auto ab = _b._position - _a._position;
    auto ac = _c._position - _a._position;

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            auto pa = _a._position - Vector2(x, y);

            auto crossed = Cross(Vector3(ab.x(), ac.x(), pa.x()), Vector3(ab.y(), ac.y(), pa.y()));

            if (std::abs(crossed.z()) < 1e-8)
                return;

            auto uv1 = crossed / crossed.z();

            auto f = 1 - uv1.x() - uv1.y();
            auto u = uv1.x();
            auto v = uv1.y();

            if (f >= 0 && u >= 0 && v >= 0)
            {
                Pixel col(
                f * _a._color.r + u * _b._color.r + v * _c._color.r,
                f * _a._color.g + u * _b._color.g + v * _c._color.g,
                f * _a._color.b + u * _b._color.b + v * _c._color.b
                );

                image->SetPixelDepth(x, y, _z, col);
            }
        }
    }
}
