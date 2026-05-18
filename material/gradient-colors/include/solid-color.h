#pragma once
#include "color-provider.h"

class SolidColor final : public ColorProvider
{

private:

    Pixel _color;

public:

    explicit SolidColor(const Pixel& color) : _color(color) {}

public:

    Pixel GetColor(int x, int y) const override { return _color; }

};