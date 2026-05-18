#pragma once
#include "drawable.h"

class ColorProvider;

class Background : public Drawable
{

private:

    const ColorProvider* _colorProvider;

public:

    explicit Background(const ColorProvider* colorProvider) : _colorProvider(colorProvider) {}

public:

    std::optional<Pixel> Apply(const Vector2& ndc, float aspectRatio) const override;

};
