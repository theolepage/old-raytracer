#pragma once

#include "vector3.hxx"

namespace raytracer
{
class Ray
{
  public:
    static constexpr float RAY_MIN_DISTANCE = 0.0001f;
    static constexpr float RAY_MAX_DISTANCE = 1.0e30f;

    explicit Ray(const Point3& pos, const Vector3& direction);

    virtual ~Ray() = default;

    Point3  get_pos() const;
    Vector3 get_direction() const;

    void set_pos(const Point3& pos);
    void set_direction(const Vector3& direction);

    Point3 at(const float t) const;

  private:
    Point3  pos_;
    Vector3 direction_;
};

Ray::Ray(const Point3& pos, const Vector3& direction)
    : pos_(pos)
    , direction_(direction)
{
}

Point3 Ray::get_pos() const { return pos_; }

Vector3 Ray::get_direction() const { return direction_; }

void Ray::set_pos(const Point3& pos) { pos_ = pos; }

void Ray::set_direction(const Vector3& direction) { direction_ = direction; }

Point3 Ray::at(const float t) const { return pos_ + direction_ * t; }

} // namespace raytracer