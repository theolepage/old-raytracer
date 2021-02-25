#pragma once

#include "light.hxx"

namespace raytracer
{
class PointLight : public Light
{
  public:
    explicit PointLight(const Vector3& pos, const Color& color);

    virtual ~PointLight() = default;
};

PointLight::PointLight(const Vector3& pos, const Color& color)
    : Light(pos, color)
{
}

} // namespace raytracer