#include <iostream>

#include "camera.hxx"
#include "image.hxx"
#include "point_light.hxx"
#include "vector3.hxx"

using namespace raytracer;

int main(void)
{
    Vector3 test(5);
    std::cout << test << std::endl;

    Image image(100, 100);
    image.save("test.ppm");

    PointLight l(Vector3(0), Color(255, 0, 0));

    Camera cam(Vector3(0), Point3(0, 0, 0), 0, 0, 0);

    std::cout << "hello" << std::endl;
}