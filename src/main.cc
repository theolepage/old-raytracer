#include <iostream>

#include "image.hxx"
#include "vector3.hxx"

using namespace raytracer;

int main(void)
{
    Vector3 test(5);
    std::cout << test << std::endl;

    Image image(100, 100);
    image.save("test.ppm");

    std::cout << "hello" << std::endl;
}