#pragma once
#include "vertical-gradient.h"
#include "../../../math/include/vector2.h"

class RadialGradient final : public GradientColor
{

private:

    Vector2 _center;

    int _radius;

public:

    explicit RadialGradient(const Pixel& start, const Pixel& end, const Vector2& center, int radius) : GradientColor(start, end),
                                                                                                                       _center(center),
                                                                                                                       _radius(radius){}

public:

    Pixel GetColor(float nx, float ny) const override;

};
