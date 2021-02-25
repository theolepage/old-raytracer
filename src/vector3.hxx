#pragma once

#include <math.h>
#include <ostream>

namespace raytracer
{
class Vector3
{
  public:
    explicit Vector3(float v);
    explicit Vector3(float x, float y, float z);

    Vector3(const Vector3& v) = default;

    virtual ~Vector3() = default;

    float length() const;

    // Operations on scalars
    Vector3 operator+(const float& v) const;
    Vector3 operator-(const float& v) const;
    Vector3 operator*(const float& v) const;
    Vector3 operator/(const float& v) const;

    // Operations on vectors
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator/(const Vector3& v) const;

    friend std::ostream& operator<<(std::ostream& out, Vector3& v);

  private:
    float x_;
    float y_;
    float z_;
};

Vector3::Vector3(float v)
    : x_(v)
    , y_(v)
    , z_(v)
{
}

Vector3::Vector3(float x, float y, float z)
    : x_(x)
    , y_(y)
    , z_(z)
{
}

float Vector3::length() const
{
    return std::sqrt((x_ * x_) + (y_ * y_) + (z_ * z_));
}

Vector3 Vector3::operator+(const float& v) const
{
    return Vector3(x_ + v, y_ + v, z_ + v);
}

Vector3 Vector3::operator-(const float& v) const
{
    return Vector3(x_ - v, y_ - v, z_ - v);
}

Vector3 Vector3::operator*(const float& v) const
{
    return Vector3(x_ * v, y_ * v, z_ * v);
}

Vector3 Vector3::operator/(const float& v) const
{
    return Vector3(x_ / v, y_ / v, z_ / v);
}

Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(x_ + v.x_, y_ + v.y_, z_ + v.z_);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(x_ - v.x_, y_ - v.y_, z_ - v.z_);
}

Vector3 Vector3::operator*(const Vector3& v) const
{
    return Vector3(x_ * v.x_, y_ * v.y_, z_ * v.z_);
}

Vector3 Vector3::operator/(const Vector3& v) const
{
    return Vector3(x_ / v.x_, y_ / v.y_, z_ / v.z_);
}

std::ostream& operator<<(std::ostream& out, Vector3& v)
{
    out << "(" << v.x_ << "; " << v.y_ << "; " << v.z_ << ")";
    return out;
}

} // namespace raytracer