#pragma once

#include <optional>

#include "object.hxx"

namespace raytracer
{
class Sphere : public Object
{
  public:
    explicit Sphere(const Point3& pos, float radius);

    virtual ~Sphere() = default;

    std::optional<float> intersect(const Ray& ray) const;

    Vector3 get_surface_normal(const Vector3& pos) const;

    TextureParams get_texture_params(const Vector3& pos) const;

  private:
    Point3 pos_;
    float  radius_;
};

Sphere::Sphere(const Point3& pos, float radius)
    : pos_(pos)
    , radius_(radius)
{
}

std::optional<float> Sphere::intersect(const Ray& ray) const
{
    // Move sphere to the center to simplify next steps
    Ray ray_copy = ray;
    ray_copy.set_pos(ray_copy.get_pos() - pos_);

    // Determine coefficients to solve quadratic equation
    float a = ray_copy.get_direction().norm(true);
    float b = 2 * dot(ray_copy.get_direction(), ray_copy.get_pos());
    float c = ray_copy.get_pos().norm(true) - (radius_ * radius_);

    // Handle no intersections
    float d = b * b - 4 * a * c;
    if (d >= 0.0f)
    {
        // Determine the two intersections point
        float t1 = (-b - std::sqrt(d)) / (2 * a);
        if (t1 > Ray::RAY_MIN_DISTANCE && t1 < Ray::RAY_MAX_DISTANCE)
            return t1;

        float t2 = (-b + std::sqrt(d)) / (2 * a);
        if (t2 > Ray::RAY_MIN_DISTANCE && t2 < Ray::RAY_MAX_DISTANCE)
            return t2;
    }

    return std::nullopt;
}

Vector3 Sphere::get_surface_normal(const Vector3&) const
{
    return Vector3(0, 0, 0);
}

TextureParams Sphere::get_texture_params(const Vector3& pos) const
{
    return texture_->get_params(pos);
}

} // namespace raytracer