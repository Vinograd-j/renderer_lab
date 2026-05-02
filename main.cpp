#include <functional>
#include <iostream>

#include "image.h"
#include "material/gradient-colors/include/horizontal-gradient.h"
#include "material/gradient-colors/include/vertical-gradient.h"
#include "shapes/include/background.h"
#include "shapes/include/circle.h"

int main()
{
    int imageWidth = 3840;
    int imageHeight = 2160;

    Image image(imageWidth, imageHeight);

    Vector2 center(0.0, 0.0);

    HorizontalGradient horizontal(Pixel(0.4, 0.85, 0.1), Pixel(0.8, 0.1, 0.43), imageWidth);
    Circle circle(1, center, &horizontal);

    VerticalGradient vertical(Pixel(0.917, 0.75, 0.2), Pixel(0.7851, 0.203, 0.9179), imageHeight);
    Background background(&vertical);


    background.Draw(image);
    circle.Draw(image);

    image.SavePPM("image");
}
