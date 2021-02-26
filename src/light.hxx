#pragma once

#include "vector3.hxx"

namespace raytracer
{
class Light
{
  public:
    explicit Light(const Vector3& pos, const Color& color);

    virtual ~Light() = default;

    Color   get_color() const;
    Vector3 get_pos() const;

  private:
    Vector3 pos_;
    Color   color_;
};

Light::Light(const Vector3& pos, const Color& color)
    : pos_(pos)
    , color_(color)
{
}

Color Light::get_color() const { return color_; }

Vector3 Light::get_pos() const { return pos_; }

} // namespace raytracer