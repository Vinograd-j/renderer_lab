#include "../include/line-dda.h"

#include <cmath>

void LineDDA::Draw(const Image& image) const
{
    double xStart = _startPoint.x();
    double yStart = _startPoint.y();

    double xEnd = _endPoint.x();
    double yEnd = _endPoint.y();

    double dx = xEnd - xStart;
    double dy = yEnd - yStart;

    int l = (int)std::max(std::abs(dx) * image.GetWidth(),
                          std::abs(dy) * image.GetHeight());

    if (l <= 0) l = 1;

    double Xinc = dx / l;
    double Yinc = dy / l;

    double x = xStart;
    double y = yStart;

    int radius = _thickness / 2;

    for (int i = 0; i <= l; i++)
    {
        int xPix = (int)std::round((x + 1.0) * 0.5 * (image.GetWidth() - 1));
        int yPix = (int)std::round((y + 1.0) * 0.5 * (image.GetHeight() - 1));

        for (int oy = -radius; oy <= radius; oy++)
        {
            for (int ox = -radius; ox <= radius; ox++)
            {
                image.SetPixel(xPix + ox, yPix + oy, _colorProvider->GetColor(x, y));
            }
        }

        x += Xinc;
        y += Yinc;
    }
}