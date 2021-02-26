#pragma once

#include <math.h>
#include <ostream>

namespace raytracer
{
class Vector3;

typedef Vector3 Point3;
typedef Vector3 Color;

class Vector3
{
  public:
    explicit Vector3();
    explicit Vector3(float v);
    explicit Vector3(float x, float y, float z);

    Vector3(const Vector3& v) = default;

    virtual ~Vector3() = default;

    float get_x() const;
    float get_y() const;
    float get_z() const;

    void set_x(const float v);
    void set_y(const float v);
    void set_z(const float v);

    Vector3 normalize() const;

    float norm(bool squared = false) const;

    Vector3& operator+=(const float& v);
    Vector3& operator-=(const float& v);
    Vector3& operator*=(const float& v);
    Vector3& operator/=(const float& v);

    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);
    Vector3& operator*=(const Vector3& v);
    Vector3& operator/=(const Vector3& v);

  private:
    float x_;
    float y_;
    float z_;
};

Vector3::Vector3()
    : Vector3(0, 0, 0)
{
}

Vector3::Vector3(float v)
    : Vector3(v, v, v)
{
}

Vector3::Vector3(float x, float y, float z)
    : x_(x)
    , y_(y)
    , z_(z)
{
}

float Vector3::get_x() const { return x_; }

float Vector3::get_y() const { return y_; }

float Vector3::get_z() const { return z_; }

void Vector3::set_x(const float v) { x_ = v; }

void Vector3::set_y(const float v) { y_ = v; }

void Vector3::set_z(const float v) { z_ = v; }

float Vector3::norm(bool squared) const
{
    float res = (x_ * x_) + (y_ * y_) + (z_ * z_);
    return squared ? res : std::sqrt(res);
}

Vector3 Vector3::normalize() const
{
    Vector3 res(*this);
    res /= norm();
    return res;
}

Vector3& Vector3::operator+=(const float& v)
{
    x_ += v;
    y_ += v;
    z_ += v;
    return *this;
}

Vector3& Vector3::operator-=(const float& v)
{
    x_ -= v;
    y_ -= v;
    z_ -= v;
    return *this;
}

Vector3& Vector3::operator*=(const float& v)
{
    x_ *= v;
    y_ *= v;
    z_ *= v;
    return *this;
}

Vector3& Vector3::operator/=(const float& v)
{
    x_ /= v;
    y_ /= v;
    z_ /= v;
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& v)
{
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& v)
{
    x_ *= v.x_;
    y_ *= v.y_;
    z_ *= v.z_;
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& v)
{
    x_ /= v.x_;
    y_ /= v.y_;
    z_ /= v.z_;
    return *this;
}
} // namespace raytracer