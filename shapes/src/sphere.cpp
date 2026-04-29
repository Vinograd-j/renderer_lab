#include "../include/sphere.h"

void Sphere::Draw(const Image& image) const
{
    for (int y = 0; y < image.GetHeight(); ++y)
    {
        for (int x = 0; x < image.GetWidth(); ++x)
        {
            if ((_center - Vector2(x, y)).LengthSquared() < _radius * _radius)
                image.SetPixel(x, y, _colorProvider->GetColor(x, y));
        }
    }
}