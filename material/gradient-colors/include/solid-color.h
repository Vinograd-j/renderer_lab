#pragma once
#include "color-provider.h"

class SolidColor final : public ColorProvider
{

private:

    Pixel _color;

public:

    explicit SolidColor(const Pixel& color) : _color(color) {}

public:

    Pixel GetColor(float, float) const override { return _color; }

};