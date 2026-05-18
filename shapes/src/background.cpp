#include "../include/background.h"

#include "../../material/gradient-colors/include/color-provider.h"

void Background::Apply(const Context* context) const
{
    const Image* image = context->GetImage();

    for (int y = 0; y < image->GetHeight(); ++y)
    {
        for (int x = 0; x < image->GetWidth(); ++x)
        {
            image->SetPixel(x, y, _colorProvider->GetColor(x, y));
        }
    }
}