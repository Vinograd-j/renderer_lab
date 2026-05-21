#pragma once

#include "../../image.h"
#include "../../math/include/vector2.h"

struct Vertex
{
    Vector2 _position;
    Pixel _color;

    explicit Vertex(const Vector2& _position, const Pixel& _color) : _position(_position), _color(_color) {}

    double x() const { return _position.x(); }
    double y() const { return _position.y(); }

};