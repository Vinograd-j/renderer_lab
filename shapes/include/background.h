#pragma once

#include "drawable.h"
#include "../../material/gradient-colors/include/color-provider.h"
#include "../../renderer/include/context.h"

class Background : public Drawable
{

private:

    const ColorProvider* _colorProvider;

public:

    explicit Background(const ColorProvider* colorProvider) : _colorProvider(colorProvider) {}

public:

    void Apply(const Context* context) const override;

};
