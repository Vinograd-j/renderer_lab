#include "image.h"

#include <fstream>
#include <stdexcept>

Image::Image(int width, int height) : _width(width), _height(height)
{
    _pixels = new Pixel*[_height];

    for (int i = 0; i < height; i++)
        _pixels[i] = new Pixel[width];

    _depth = new float*[_height];
    for (int i = 0; i < _height; i++)
        _depth[i] = new float[_width];
}

Image::~Image()
{
    for (int i = 0; i < _height; i++)
        delete[] _pixels[i];

    for (int i = 0; i < _height; i++)
        delete[] _depth[i];

    delete[] _pixels;
    delete[] _depth;
}

void Image::SetPixel(int x, int y, const Pixel& color) const
{
    if (x < 0 || x >= _width || y < 0 || y >= _height)
        return;

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

void Image::SetPixelDepth(int x, int y, float z, const Pixel& pixel) const
{
    if (x < 0 || x >= _width || y < 0 || y >= _height)
        return;

    if (z < _depth[y][x])
    {
        _depth[y][x] = z;
        _pixels[y][x] = pixel;
    }
}

void Image::ClearDepthBuffer(float value) const
{
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            _depth[y][x] = value;
}
