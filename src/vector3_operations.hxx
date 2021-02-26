#pragma once

#include <ostream>

#include "vector3.hxx"

namespace raytracer
{
Vector3 operator+(const Vector3& lhs, float rhs)
{
    return Vector3(lhs.get_x() + rhs, lhs.get_y() + rhs, lhs.get_z() + rhs);
}

Vector3 operator-(const Vector3& lhs, float rhs)
{
    return Vector3(lhs.get_x() - rhs, lhs.get_y() - rhs, lhs.get_z() - rhs);
}

Vector3 operator*(const Vector3& lhs, float rhs)
{
    return Vector3(lhs.get_x() * rhs, lhs.get_y() * rhs, lhs.get_z() * rhs);
}

Vector3 operator/(const Vector3& lhs, float rhs)
{
    return Vector3(lhs.get_x() / rhs, lhs.get_y() / rhs, lhs.get_z() / rhs);
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.get_x() + rhs.get_x(),
                   lhs.get_y() + rhs.get_y(),
                   lhs.get_z() + rhs.get_z());
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.get_x() - rhs.get_x(),
                   lhs.get_y() - rhs.get_y(),
                   lhs.get_z() - rhs.get_z());
}

Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.get_x() * rhs.get_x(),
                   lhs.get_y() * rhs.get_y(),
                   lhs.get_z() * rhs.get_z());
}

Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.get_x() / rhs.get_x(),
                   lhs.get_y() / rhs.get_y(),
                   lhs.get_z() / rhs.get_z());
}

float dot(const Vector3& lhs, const Vector3& rhs)
{
    return lhs.get_x() * rhs.get_x() + lhs.get_y() * rhs.get_y() +
           lhs.get_z() * rhs.get_z();
}

Vector3 cross(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.get_y() * rhs.get_z() - lhs.get_z() * rhs.get_y(),
                   lhs.get_z() * rhs.get_x() - lhs.get_x() * rhs.get_z(),
                   lhs.get_x() * rhs.get_y() - lhs.get_y() * rhs.get_x());
}

std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
    out << "(" << v.get_x() << "; " << v.get_y() << "; " << v.get_z() << ")";
    return out;
}

} // namespace raytracer