
#pragma once

#include "texture_material.hxx"

namespace raytracer
{
class UniformTexture : public TextureMaterial
{
  public:
    explicit UniformTexture();
    explicit UniformTexture(const Color& color);

    virtual ~UniformTexture() = default;

    TextureParams get_params(const Vector3& pos) const;

  private:
    TextureParams params_;
};

UniformTexture::UniformTexture()
    : UniformTexture(Color(0.07f, 0.34f, 0.92f))
{
}

UniformTexture::UniformTexture(const Color& color)
{
    params_.color = color;
    params_.k_d   = 0.9f;
    params_.k_s   = 0.17f;
    params_.n_s   = 1.0f;
}

TextureParams UniformTexture::get_params(const Vector3&) const
{
    return params_;
}

} // namespace raytracer