#pragma once

#include "../../renderer/include/context.h"

class Drawable
{

public:

    virtual void Apply(const Context* context) const = 0;

    virtual ~Drawable() = default;

};
