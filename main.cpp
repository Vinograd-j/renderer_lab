#include <functional>
#include <iostream>

#include "image.h"
#include "material/gradient-colors/include/radial-gradient.h"
#include "material/gradient-colors/include/horizontal-gradient.h"
#include "material/gradient-colors/include/vertical-gradient.h"
#include "shapes/include/background.h"
#include "shapes/include/circle.h"
#include "shapes/include/line-dda.h"

int main()
{
    int imageWidth = 3840;
    int imageHeight = 2160;

    Image image(imageWidth, imageHeight);

    Vector2 center(0.0, 0.0);

    RadialGradient radial(Pixel(0.42, 0.85, 0.13), Pixel(0.81, 0.18, 0.4352), center, 1.0);
    Circle circle(1, center, &radial);

    VerticalGradient vertical(Pixel(0.917, 0.75, 0.2), Pixel(0.7851, 0.203, 0.9179), imageHeight);
    Background background(&vertical);

    HorizontalGradient horizontal(Pixel(0, 1, 0), Pixel(0, 0, 1), imageHeight);
    LineDDA lineDDA(15, Vector2(-1, -1), Vector2(1, 1), &horizontal);

    background.Draw(image);
    //8circle.Draw(image);
    lineDDA.Draw(image);

    image.SavePPM("image");
}
