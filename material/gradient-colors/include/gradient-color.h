#pragma once
#include "color-provider.h"

class GradientColor : public ColorProvider
{

private:

    Pixel _startColor;

    Pixel _endColor;

public:

    explicit GradientColor(const Pixel& startColor, const Pixel& endColor) : _startColor(startColor),
                                                                                           _endColor(endColor) {}

public:

    Pixel GetColor(float nx, float ny) const override = 0;

public:

    Pixel GetStartColor() const { return _startColor; }

    Pixel GetEndColor() const { return _endColor; }

};