#include <functional>
#include <iostream>

#include "image.h"
#include "material/gradient-colors/include/radial-gradient.h"
#include "material/gradient-colors/include/horizontal-gradient.h"
#include "material/gradient-colors/include/vertical-gradient.h"
#include "renderer/include/renderer.h"
#include "shapes/include/background.h"
#include "shapes/include/circle.h"
#include "shapes/include/line-dda.h"
#include "shapes/include/triangle.h"

int main()
{
    int imageWidth = 3840;
    int imageHeight = 2160;

    std::unique_ptr<Image> image = std::make_unique<Image>(imageWidth, imageHeight);

    Vector2 center(0.5, 0.5);

    RadialGradient radial(Pixel(0.42, 0.85, 0.13), Pixel(0.81, 0.18, 0.4352), center, 1.0);
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(1, center, &radial);

    VerticalGradient vertical(Pixel(0.917, 0.75, 0.2), Pixel(0.7851, 0.203, 0.9179), imageHeight);
    std::unique_ptr<Background> background = std::make_unique<Background>(&vertical);

    HorizontalGradient horizontal(Pixel(0, 1, 0), Pixel(0, 0, 1), imageHeight);
    std::unique_ptr<LineDDA> lineDDA = std::make_unique<LineDDA>(0.01, Vector2(-1, -1), Vector2(1, 1), &horizontal);


    std::unique_ptr<Triangle> triangle = std::make_unique<Triangle>(Vector2(0, -0.2), Vector2(0.2, 0.2), Vector2(-0.2, 0.2), &vertical);

    std::vector<const Drawable*> shapes;
    // shapes.push_back(background.get());
    // shapes.push_back(circle.get());
    //shapes.push_back(lineDDA.get());
    shapes.push_back(triangle.get());


    Context context(image.get());
    Renderer renderer;

    renderer.Render(context, shapes);

    image->SavePPM("image");
}
