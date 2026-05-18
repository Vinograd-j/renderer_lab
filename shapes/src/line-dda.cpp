#include "../include/line-dda.h"

#include <optional>

void LineDDA::Apply(const Context* context) const
{
    // if (IsPointBelonging(ndc, aspectRatio))
    //     return _colorProvider->GetColor(ndc.x(), ndc.y());
    //
    // return std::nullopt;
}

bool LineDDA::IsPointBelonging(const Vector2& ndc, float aspectRatio) const
{
    Vector2 ab = _endPoint - _startPoint;
    Vector2 ac = ndc - _startPoint;

    auto t = Dot(ac, ab) / ab.LengthSquared();

    if (t < 0 || t > 1) return false;

    auto d = _startPoint + ab * t;

    Vector2 corrected(
        (d.x() - ndc.x()) * aspectRatio,
        d.y() - ndc.y()
    );

    if ((corrected).Length() <= _thickness) return true;

    return false;

}