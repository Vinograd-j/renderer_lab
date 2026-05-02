#pragma once

#include "drawable.h"
#include "../../image.h"
#include "../../material/gradient-colors/include/color-provider.h"
#include "../../math/include/vector2.h"

class Circle : Drawable
{

private:

    float _radius;

    Vector2 _center;


    const ColorProvider* _colorProvider;

public:

    explicit Circle(float radius, const Vector2& center, const ColorProvider* colorProvider) : _radius(radius), _center(center), _colorProvider(colorProvider) {}

public:

    void Draw(const Image& image) const override;

};