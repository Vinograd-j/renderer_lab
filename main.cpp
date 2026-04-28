#include <functional>
#include <iostream>

#include "image.h"

int main()
{
    int imageWidth = 800;
    int imageHeight = 600;

    Image image(imageWidth, imageHeight);

    for (int y = 0; y < imageHeight; y++)
    {
        for (int x = 0; x < imageWidth; x++)
        {
            auto r = double(y) / (imageHeight - 1);
            auto g = double(x) / (imageWidth - 1);
            auto b = 0.0;

            image.SetPixel(y, x, Pixel(r, g, b));
        }
    }

    image.SavePPM("image");
}
