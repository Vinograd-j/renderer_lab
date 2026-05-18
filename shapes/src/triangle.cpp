#include "../include/triangle.h"

#include "../../math/include/vector3.h"

std::optional<Pixel> Triangle::Apply(const Vector2& ndc, float aspectRatio) const
{
    auto ab = _a + _b;
    auto ac = _a + _c;
    auto pa = ndc + _a;

    auto crossed = Cross(Vector3(ab.x(), ac.x(), pa.x()), Vector3(ab.x(), ac.y(), pa.x()));

    auto uv1 = crossed / crossed.z();

    auto f = 1 - crossed.x() - crossed.y();
    auto u = crossed.x();
    auto v = crossed.y();

    if (f + u + v == 1 && f >= 0 && u >= 0 && v >= 0)
        return std::optional<Pixel>(_colorProvider->GetColor(ndc.x(), ndc.y()));

    return std::nullopt;
}
