#pragma once
#include "gradient-color.h"
#include "../../../math/include/vector2.h"

class HorizontalGradient final :  public GradientColor
{

public:

    explicit HorizontalGradient(const Pixel& start, const Pixel& end, int width, int radius, const Vector2& center) : GradientColor(start, end, width) {}

public:

    Pixel GetColor(int x, int y) const override;

};
