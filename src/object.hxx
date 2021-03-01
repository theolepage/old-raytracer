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
    explicit Object(const Point3& pos);

    Point3 get_pos() const;

    void set_texture(TextureMaterial* texture);

    virtual std::optional<float> intersect(const Ray& ray) const = 0;

    virtual Vector3 get_surface_normal(const Vector3& pos) const = 0;

    virtual TextureParams get_texture_params(const Vector3& pos) const = 0;

  protected:
    Point3           pos_;
    TextureMaterial* texture_;
};

Object::Object(const Point3& pos)
    : pos_(pos)
    , texture_(new UniformTexture())
{
}

Point3 Object::get_pos() const { return pos_; }

void Object::set_texture(TextureMaterial* texture) { texture_ = texture; }

} // namespace raytracer