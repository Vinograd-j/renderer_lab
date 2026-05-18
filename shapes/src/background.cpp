#include "../include/background.h"

#include "../../material/gradient-colors/include/color-provider.h"

std::optional<Pixel> Background::Apply(const Vector2& ndc, float aspectRatio) const
{
    return _colorProvider->GetColor(ndc.x(), ndc.y());
}