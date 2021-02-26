#pragma once

#include "vector3.hxx"

namespace raytracer
{
struct TextureParams
{
    Color color;
    float k_d; // capacity of surface to be diffusing
    float k_s; // capacity of surface to be reflecting
    float n_s;
};

class TextureMaterial
{
  public:
    explicit TextureMaterial() = default;

    virtual ~TextureMaterial() = default;

    virtual TextureParams get_params(const Vector3& pos) const = 0;
};

} // namespace raytracer