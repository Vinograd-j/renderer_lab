#pragma once
#include <span>

#include "../../shapes/include/drawable.h"


class Renderer
{

public:

    void Render(const Context& context, const std::span<const Drawable* const>& shapes);

};