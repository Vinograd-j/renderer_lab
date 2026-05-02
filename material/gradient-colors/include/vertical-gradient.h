#pragma once
#include "gradient-color.h"

class VerticalGradient final : public GradientColor
{

private:

    int _imageHeight;

public:

    explicit VerticalGradient(const Pixel& start, const Pixel& end, int height) : GradientColor(start, end),
                                                                                  _imageHeight(height) {}

public:

    Pixel GetColor(float nx, float ny) const override;

};