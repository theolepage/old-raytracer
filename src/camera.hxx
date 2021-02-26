#pragma once

#include "ray.hxx"
#include "vector3.hxx"

namespace raytracer
{
class Camera
{
  public:
    explicit Camera();

    explicit Camera(const Vector3& pos,
                    const Point3&  target,
                    float          alpha,
                    float          beta,
                    float          z_min);

    virtual ~Camera() = default;

    Ray create_ray(const Vector3& point) const;

  private:
    Vector3 pos_;

    Vector3 forward_;
    Vector3 right_;
    Vector3 up_;

    float width_;
    float height_;
};

Camera::Camera() {}

Camera::Camera(const Vector3& pos,
               const Point3&  target,
               float          alpha,
               float          beta,
               float)
    : pos_(pos)
{
    const Vector3 up_guide(0, 1, 0);

    forward_ = (target - pos).normalize();
    right_   = cross(forward_, up_guide).normalize();
    up_      = cross(right_, forward_);

    height_ = std::tanh(alpha);
    width_  = height_ * beta;
}

Ray Camera::create_ray(const Vector3& point) const
{
    const Vector3 direction = forward_ + (right_ * width_ * point.get_x()) +
                              (up_ * height_ * point.get_y());

    return Ray(pos_, direction.normalize());
}

} // namespace raytracer