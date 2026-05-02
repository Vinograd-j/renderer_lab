#pragma once
#include "gradient-color.h"

class HorizontalGradient final :  public GradientColor
{

public:

    explicit HorizontalGradient(const Pixel& start, const Pixel& end, int width) : GradientColor(start, end, width) {}

public:

    Pixel GetColor(int x, int y) const override;

};