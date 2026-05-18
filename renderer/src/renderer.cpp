#include "../include/renderer.h"

#include <span>

void Renderer::Render(const Context& context, const std::span<const Drawable* const>& shapes)
{
    auto image = context.GetImage();
    for (int y = 0; y < image->GetHeight(); y++)
    {
        for (int x = 0; x < image->GetWidth(); x++)
        {
            Vector2 ndc = context.PixelToNDC(x, y);

            Pixel finalColor(0, 0, 0);

            for (auto& shape : shapes)
            {
                auto col = shape->Apply(ndc, context.GetAspectRatio());
                if (col.has_value())
                    finalColor = col.value();
            }

            image->SetPixel(x, y, finalColor);
        }
    }
}