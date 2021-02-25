
#pragma once

#include "texture_material.hxx"

namespace raytracer
{
class UniformTexture
{
  public:
    explicit UniformTexture() = default;

    virtual ~UniformTexture() = default;

    virtual TextureParams get_params(const Vector3& pos) const;
};

TextureParams UniformTexture::get_params(const Vector3&) const
{
    TextureParams res;
    res.k_d = 0;
    res.k_s = 0;
    return res;
}

} // namespace raytracer