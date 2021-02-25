#pragma once

#include "vector3.hxx"

namespace raytracer
{
class Color : public Vector3
{
  public:
    explicit Color(float r, float g, float b);
};

Color::Color(float r, float g, float b)
    : Vector3(r, g, b)
{
}
} // namespace raytracer
