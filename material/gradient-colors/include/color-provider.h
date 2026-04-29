#pragma once
#include "../../../image.h"

class ColorProvider
{

public:

    virtual Pixel GetColor(int x, int y) const = 0;

    virtual ~ColorProvider() = default;

};