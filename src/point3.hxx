#pragma once

#include "vector3.hxx"

namespace raytracer
{
class Point3 : public Vector3
{
  public:
    explicit Point3(float x, float y, float z);
};

Point3::Point3(float x, float y, float z)
    : Vector3(x, y, z)
{
}
} // namespace raytracer
