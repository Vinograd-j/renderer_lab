#include "../include/circle.h"

void Circle::Apply(const Context* context) const
{
    const Image* image = context->GetImage();

    for (int y = static_cast<int>(_center.y() - _radius); y <= _center.y() + _radius; y++)
    {
        for (int x = static_cast<int>(_center.x() - _radius); x <= _center.x() + _radius; ++x)
        {
            if ((_center - Vector2(x, y)).LengthSquared() <= _radius * _radius)
                image->SetPixel(x, y, _colorProvider->GetColor(x, y));
        }
    }
}
