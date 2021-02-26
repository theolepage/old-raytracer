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
    explicit Object();

    void set_texture(TextureMaterial* texture);

    virtual std::optional<float> intersect(const Ray& ray) const = 0;

    virtual Vector3 get_surface_normal(const Vector3& pos) const = 0;

    virtual TextureParams get_texture_params(const Vector3& pos) const = 0;

  protected:
    TextureMaterial* texture_;
};

Object::Object()
    : texture_(new UniformTexture())
{
}

void Object::set_texture(TextureMaterial* texture) { texture_ = texture; }

} // namespace raytracer