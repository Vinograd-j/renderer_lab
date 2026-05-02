#include "../include/background.h"

#include "../../material/gradient-colors/include/color-provider.h"

void Background::Draw(const Image& image) const
{
    float aspectRatio = static_cast<float>(image.GetWidth()) / static_cast<float>(image.GetHeight());

    for (int y = 0; y < image.GetHeight(); ++y)
    {
        for (int x = 0; x < image.GetWidth(); ++x)
        {
            float nx = (2.0f * static_cast<float>(x) / static_cast<float>(image.GetWidth()) - 1.0f) * aspectRatio;
            float ny = 2.0f * static_cast<float>(y) / static_cast<float>(image.GetHeight()) - 1.0f;

            image.SetPixel(x, y, _colorProvider->GetColor(nx, ny));
        }
    }
}
