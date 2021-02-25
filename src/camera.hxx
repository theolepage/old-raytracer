#pragma once

#include "point3.hxx"
#include "vector3.hxx"

namespace raytracer
{
class Camera
{
  public:
    explicit Camera(const Vector3& pos,
                    const Point3&  target,
                    float          alpha,
                    float          beta,
                    float          z_min);

    virtual ~Camera() = default;

  private:
    Vector3 pos_;
    Point3  target_;
    float   alpha_;
    float   beta_;
    float   z_min_;
};

Camera::Camera(const Vector3& pos,
               const Point3&  target,
               float          alpha,
               float          beta,
               float          z_min)
    : pos_(pos)
    , target_(target)
    , alpha_(alpha)
    , beta_(beta)
    , z_min_(z_min)
{
}

} // namespace raytracer