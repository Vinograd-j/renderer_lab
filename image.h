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

    void SetPixel(int x, int y, const Pixel& color) const;

    void SavePPM(const std::string& fileName) const;

public:

    int GetWidth() const { return _width; }

    int GetHeight() const { return _height; }

};
