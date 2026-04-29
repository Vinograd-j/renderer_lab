#pragma once
#include "drawable.h"

class ColorProvider;

class Background : Drawable
{

private:

    const ColorProvider* _colorProvider;

public:

    explicit Background(const ColorProvider* colorProvider) : _colorProvider(colorProvider) {}

public:

    void Draw(const Image& image) const override;

};
