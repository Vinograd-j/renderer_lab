#pragma once
#include "drawable.h"
#include "../../material/gradient-colors/include/color-provider.h"
#include "../../math/include/vector2.h"

class LineDDA : public Drawable
{

private:

    float _thickness;

    Vector2 _startPoint;

    Vector2 _endPoint;


    const ColorProvider* _colorProvider;

public:

    explicit LineDDA(float thickness, const Vector2& start_point, const Vector2& end_point, const ColorProvider* colorProvider) :
                                                        _thickness(thickness),
                                                        _startPoint(start_point),
                                                        _endPoint(end_point),
                                                        _colorProvider(colorProvider)   {}

public:

    std::optional<Pixel> Apply(const Vector2& ndc, float aspectRatio) const override;

private:

    bool IsPointBelonging(const Vector2& ndc, float aspectRatio) const;

};