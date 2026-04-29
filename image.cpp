#include "image.h"

#include <fstream>
#include <stdexcept>

Image::Image(int width, int height) : _width(width), _height(height)
{
    _pixels = new Pixel*[_height];

    for (int i = 0; i < height; i++)
        _pixels[i] = new Pixel[width];
}

Image::~Image()
{
    for (int i = 0; i < _height; i++)
        delete[] _pixels[i];

    delete[] _pixels;
}

void Image::SetPixel(int x, int y, const Pixel& color) const
{
    _pixels[y][x] = color;
}

void Image::SavePPM(const std::string& fileName) const
{
    std::ofstream file(fileName + ".ppm", std::ios::binary);

    file << "P6\n" << _width << " " << _height << "\n255\n";

    for (int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            auto ir = static_cast<unsigned char>(255.999 * _pixels[y][x].r);
            auto ig = static_cast<unsigned char>(255.999 * _pixels[y][x].g);
            auto ib = static_cast<unsigned char>(255.999 * _pixels[y][x].b);

            file.write(reinterpret_cast<char*>(&ir), 1);
            file.write(reinterpret_cast<char*>(&ig), 1);
            file.write(reinterpret_cast<char*>(&ib), 1);
        }
    }
}