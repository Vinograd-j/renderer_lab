#pragma once
#include "color-provider.h"

class GradientColor : public ColorProvider
{

private:

    Pixel _startColor;

    Pixel _endColor;

    int _axisSize;

public:

    explicit GradientColor(const Pixel& startColor, const Pixel& endColor, int axisSize) : _startColor(startColor),
                                                                                           _endColor(endColor),
                                                                                           _axisSize(axisSize) {}

public:

    Pixel GetColor(int x, int y) const override = 0;

public:

    Pixel GetStartColor() const { return _startColor; }

    Pixel GetEndColor() const { return _endColor; }

    int GetAxisSize() const { return _axisSize; }

};