#pragma once

#include "vector3.hxx"

namespace raytracer
{
class Light
{
  public:
    explicit Light(const Vector3& pos, const Color& color);

    virtual ~Light() = default;

  private:
    Vector3 pos_;
    Color   color_;
};

Light::Light(const Vector3& pos, const Color& color)
    : pos_(pos)
    , color_(color)
{
}

} // namespace raytracer