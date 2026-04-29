#pragma once
#include "../../image.h"

class Drawable
{

public:

    virtual void Draw(const Image& image) const = 0;

    virtual ~Drawable() = default;

};