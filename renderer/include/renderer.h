#pragma once
#include <span>
#include <vector>

#include "../../shapes/include/drawable.h"

struct Context
{

private:

    const Image* _image;

    float _aspectRatio;

public:

    explicit Context(const Image* image) : _image(image)
    {
        _aspectRatio = static_cast<float>(_image->GetWidth()) / static_cast<float>(_image->GetHeight());
    }

    Vector2 PixelToNDC(int x, int y) const
    {
        float nx = (2.0f * x / (_image->GetWidth() - 1) - 1.0f);
        float ny =  2.0f * y / (_image->GetHeight() - 1) - 1.0f;
        return Vector2(nx, ny);
    }

    const Image* GetImage() const { return _image; }

    float GetAspectRatio() const { return _aspectRatio; }

};

class Renderer
{

public:

    void Render(const Context& context, const std::span<const Drawable* const>& shapes);

};