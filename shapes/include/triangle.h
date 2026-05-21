#pragma once

#include "drawable.h"
#include "triangle.h"
#include "vertex.h"
#include "../../material/gradient-colors/include/color-provider.h"

class Triangle : public Drawable
{

private:

    Vertex _a, _b, _c;

    float _z;

    const ColorProvider* _colorProvider;

public:

    explicit Triangle(const Vertex& a, const Vertex& b, const Vertex& c, float z, const ColorProvider* colorProvider) : _a(a), _b(b), _c(c), _z(z), _colorProvider(colorProvider) {}

public:

    void Apply(const Context* context) const override;

};
