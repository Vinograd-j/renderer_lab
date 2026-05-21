#include "../include/circle.h"

#include <cmath>
#include <vector>

#include "../../material/gradient-colors/include/solid-color.h"
#include "../include/triangle.h"

#define PI 3.1415926535897932384626433832795

void Circle::Apply(const Context* context) const
{
    std::vector<Vector2> points;

    for (int i = 0; i < _segmentsCount; ++i)
    {
        float angle = (2.0f * PI * i) / _segmentsCount;
        float x = _center.x() + _radius * std::cos(angle);
        float y = _center.y() + _radius * std::sin(angle);
        points.emplace_back(x, y);
    }

    std::vector<Triangle> triangles;
    auto color = SolidColor(Pixel(1, 0, 0));

    for (int i = 0; i < _segmentsCount; ++i)
    {
        int next = (i + 1) % _segmentsCount;
        triangles.emplace_back(Vertex(_center, Pixel(1,1,1)), Vertex(points[i], Pixel(0,0,1)), Vertex(points[next], Pixel(0,0,1)), _z, &color);
    }

    for (const auto& triangle : triangles)
        triangle.Apply(context);
}
