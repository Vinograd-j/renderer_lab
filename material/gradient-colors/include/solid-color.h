#pragma once
#include "color-provider.h"

class SolidColor : public ColorProvider
{

private:

    Pixel _color;

public:

    explicit SolidColor(const Pixel& color) : _color(color) {}

public:

    Pixel GetColor(int, int) const override { return _color; }

};