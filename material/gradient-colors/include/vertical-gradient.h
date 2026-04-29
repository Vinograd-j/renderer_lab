#pragma once
#include "gradient-color.h"

class VerticalGradient final : public GradientColor
{

public:

    explicit VerticalGradient(const Pixel& start, const Pixel& end, int height) : GradientColor(start, end, height) {}

public:

    Pixel GetColor(int x, int y) const override;

};
