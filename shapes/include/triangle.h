#pragma once
#include "drawable.h"
#include "triangle.h"
#include "../../material/gradient-colors/include/color-provider.h"

class Triangle : public Drawable
{

private:

    Vector2 _a, _b, _c;


    const ColorProvider* _colorProvider;

public:

    explicit Triangle(const Vector2& a, const Vector2& b, const Vector2& c, const ColorProvider* colorProvider) : _a(a), _b(b), _c(c), _colorProvider(colorProvider) {}

public:

    std::optional<Pixel> Apply(const Vector2& ndc, float aspectRatio) const override;

};
