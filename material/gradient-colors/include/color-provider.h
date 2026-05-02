#pragma once

#include "../../../image.h"

class ColorProvider
{

public:

    virtual Pixel GetColor(float nx, float ny) const = 0;

    virtual ~ColorProvider() = default;

};