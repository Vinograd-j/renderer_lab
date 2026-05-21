#include "../include/renderer.h"

#include <span>

void Renderer::Render(const Context& context, const std::span<const Drawable* const>& shapes)
{
    context.GetImage()->ClearDepthBuffer(1e9f);
    for (const auto& shape : shapes)
        shape->Apply(&context);
}