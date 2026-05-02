#pragma once
#include "gradient-color.h"

class HorizontalGradient final : public GradientColor
{

private:

    int _imageWidth;

public:

    explicit HorizontalGradient(const Pixel& start, const Pixel& end, int width) : GradientColor(start, end),
                                                                                   _imageWidth(width){}

public:

    Pixel GetColor(float nx, float ny) const override;

};