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
    int imageWidth = 1920;
    int imageHeight = 1080;

    std::unique_ptr<Image> image = std::make_unique<Image>(imageWidth, imageHeight);

    Vector2 center(
        imageWidth * 0.5f,
        imageHeight * 0.5f
    );

    RadialGradient radial(
        Pixel(0.42, 0.85, 0.13),
        Pixel(0.81, 0.18, 0.4352),
        center,
        std::min(imageWidth, imageHeight) * 0.5f
    );

    std::unique_ptr<Circle> circle =
        std::make_unique<Circle>(
            std::min(imageWidth, imageHeight) * 0.5f,
            center,
            &radial,
            64
        );

    VerticalGradient vertical(
        Pixel(0.917, 0.75, 0.2),
        Pixel(0.7851, 0.203, 0.9179),
        imageHeight
    );

    HorizontalGradient horizontal(
        Pixel(0, 1, 0),
        Pixel(0, 0, 1),
        imageWidth
    );

    std::unique_ptr<Background> background =
        std::make_unique<Background>(&horizontal);


    std::unique_ptr<LineDDA> lineDDA =
        std::make_unique<LineDDA>(
            1.0f,
            Vector2(0, 0),
            Vector2(imageWidth, imageHeight),
            &horizontal
        );

    Vector2 c(imageWidth * 0.5f, imageHeight * 0.5f);
    float s = 0.2f;

    std::unique_ptr<Triangle> triangle =
        std::make_unique<Triangle>(
            Vector2(c.x(), c.y() - s * imageHeight),
            Vector2(c.x() + s * imageWidth, c.y() + s * imageHeight),
            Vector2(c.x() - s * imageWidth, c.y() + s * imageHeight),
            &vertical
        );


    std::vector<const Drawable*> shapes;
    //shapes.push_back(background.get());
    shapes.push_back(circle.get());
    //shapes.push_back(lineDDA.get());
    //shapes.push_back(triangle.get());


    Context context(image.get());
    Renderer renderer;

    renderer.Render(context, shapes);

    image->SavePPM("image");
}
