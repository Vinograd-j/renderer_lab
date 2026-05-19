#pragma once

#include "drawable.h"
#include "../../image.h"
#include "../../material/gradient-colors/include/color-provider.h"
#include "../../math/include/vector2.h"

class Circle : public Drawable
{

private:

    float _radius;

    Vector2 _center;

    int _segmentsCount;

    const ColorProvider* _colorProvider;

public:

    explicit Circle(float radius, const Vector2& center, const ColorProvider* colorProvider, int segmentsCount) : _radius(radius),
                                                                                                                  _center(center),
                                                                                                                  _colorProvider(colorProvider),
                                                                                                                  _segmentsCount(segmentsCount) {}

public:
    void Apply(const Context* context) const override;

};