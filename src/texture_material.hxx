#pragma once

#include "color.hxx"
#include "vector3.hxx"

namespace raytracer
{
struct TextureParams
{
    float k_d;
    float k_s;
};

class TextureMaterial
{
  public:
    explicit TextureMaterial() = default;

    virtual ~TextureMaterial() = default;

    virtual TextureParams get_params(const Vector3& pos) const = 0;
};

} // namespace raytracer