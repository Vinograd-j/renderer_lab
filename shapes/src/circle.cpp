#include "../include/circle.h"

void Circle::Draw(const Image& image) const
{
    float aspectRatio = static_cast<float>(image.GetWidth()) / static_cast<float>(image.GetHeight());

    for (int y = 0; y < image.GetHeight(); ++y)
    {
        for (int x = 0; x < image.GetWidth(); ++x)
        {
            float nx = (2.0f * static_cast<float>(x) / static_cast<float>(image.GetWidth()) - 1.0f) * aspectRatio;
            float ny = 2.0f * static_cast<float>(y) / static_cast<float>(image.GetHeight()) - 1.0f;

            if ((_center - Vector2(nx, ny)).LengthSquared() < _radius * _radius)
                image.SetPixel(x, y, _colorProvider->GetColor(x, y));
        }
    }
}