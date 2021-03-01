
#pragma once

#include <cmath>

#include "texture_material.hxx"

namespace raytracer
{
class FloorTexture : public TextureMaterial
{
  public:
    explicit FloorTexture();

    virtual ~FloorTexture() = default;

    TextureParams get_params(const Vector3& pos) const;

  private:
    TextureParams params_;
};

FloorTexture::FloorTexture()
{
    params_.color = Color(0, 0, 0);
    params_.k_d   = 0.9f;
    params_.k_s   = 0.3f; // 0.17f
    params_.n_s   = 1.0f;
}

TextureParams FloorTexture::get_params(const Vector3& pos) const
{
    uint  size   = 10;
    float offset = 1000;

    Color color1(0.2, 0.2, 0.2);
    Color color2(1, 1, 1);

    uint x = static_cast<int>(offset + std::round(pos.get_x()));
    uint z = static_cast<int>(offset + std::round(pos.get_z()));

    TextureParams res = params_;
    if (x % size >= size / 2)
    {
        if (z % size >= size / 2)
            res.color = color1;
        else
            res.color = color2;
    }
    else
    {
        if (z % size < size / 2)
            res.color = color1;
        else
            res.color = color2;
    }

    return res;
}

} // namespace raytracer