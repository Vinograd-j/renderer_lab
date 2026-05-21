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

    float** _depth;

public:

    explicit Image(int width, int height);

    ~Image();

public:

    void SavePPM(const std::string& fileName) const;

    void SetPixelDepth(int x, int y, float z, const Pixel& pixel) const;

    void ClearDepthBuffer(float value) const;

public:

    int GetWidth() const { return _width; }

    int GetHeight() const { return _height; }

private:

    void SetPixel(int x, int y, const Pixel& color) const;

};
