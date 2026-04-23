#pragma once
#include <string>

struct Pixel
{
    double r, g, b;
};

class Image
{

private:

    int _width;

    int _height;

    Pixel** _pixels;

public:

    explicit Image(int width, int height);

    ~Image();

public:

    void SetPixel(int y, int x, const Pixel& color) const;

    void SavePPM(const std::string& fileName) const;

};
