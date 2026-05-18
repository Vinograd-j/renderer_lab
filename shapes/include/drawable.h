#pragma once
#include "../../image.h"
#include "../../math/include/vector2.h"

class Drawable
{

public:

    virtual std::optional<Pixel> Apply(const Vector2& ndc, float aspectRatio) const = 0;

    virtual ~Drawable() = default;

};
