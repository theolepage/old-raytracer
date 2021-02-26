#pragma once

#include <memory>
#include <optional>

#include "ray.hxx"
#include "texture_material.hxx"
#include "uniform_texture.hxx"
#include "vector3.hxx"

namespace raytracer
{
class Object
{
  public:
    virtual std::optional<float> intersect(const Ray& ray) const = 0;

    virtual Vector3 get_surface_normal(const Vector3& pos) const = 0;

    virtual TextureParams get_texture_params(const Vector3& pos) const = 0;

  protected:
    const std::shared_ptr<TextureMaterial> texture_;
};
} // namespace raytracer