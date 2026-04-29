#include <functional>
#include <iostream>

#include "image.h"
#include "material/gradient-colors/include/horizontal-gradient.h"
#include "material/gradient-colors/include/vertical-gradient.h"
#include "shapes/include/background.h"
#include "shapes/include/sphere.h"

int main()
{
    int imageWidth = 1920;
    int imageHeight = 1080;

    Image image(imageWidth, imageHeight);

    int count = 6;
    float radius = 400.0f;

    Vector2 center(imageWidth / 2, imageHeight / 2);

    std::vector<Sphere> spheres;
    std::vector<std::unique_ptr<ColorProvider>> gradients;

    for (int i = 0; i < count; i++)
    {
        float t = float(i) / count;
        float angle = t * 2.0f * 3.1415926f;

        int x = center.x() + int(radius * cos(angle));
        int y = center.y() + int(radius * sin(angle));

        // разные частоты и сдвиги по каналам
        float r = 0.5f + 0.5f * sin(angle * 3.0f);
        float g = 0.5f + 0.5f * sin(angle * 5.0f + 2.0f);
        float b = 0.5f + 0.5f * sin(angle * 7.0f + 4.0f);

        // усиление контраста (делает "жёстче" различия)
        r = pow(r, 0.4f);
        g = pow(g, 1.8f);
        b = pow(b, 0.7f);

        gradients.push_back(std::make_unique<HorizontalGradient>(
            Pixel(r, g, b),
            Pixel(1.0f - b, 1.0f - r, 1.0f - g),
            imageHeight,
            radius,
            center
        ));

        spheres.emplace_back(
            150,
            Vector2(x, y),
            gradients.back().get()
        );
    }

    VerticalGradient vertical(Pixel(0.917, 0.75, 0.2), Pixel(0.7851, 0.203, 0.9179), imageHeight);
    Background background(&vertical);


    background.Draw(image);
    for (const auto& sphere: spheres)
        sphere.Draw(image);

    image.SavePPM("image");
}
