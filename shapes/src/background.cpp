#include "../include/background.h"

#include "../../material/gradient-colors/include/color-provider.h"

void Background::Draw(const Image& image) const
{
    for (int y = 0; y < image.GetHeight(); ++y)
    {
        for (int x = 0; x < image.GetWidth(); ++x)
        {
            image.SetPixel(x, y, _colorProvider->GetColor(x, y));
        }
    }
}
