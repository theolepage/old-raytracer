#include <iostream>

#include "vector3_operations.hxx"

#include "image.hxx"
#include "renderer.hxx"
#include "scene.hxx"
#include "sphere.hxx"

using namespace raytracer;

int main(void)
{
    uint  width        = 1920;
    uint  height       = 1080;
    float aspect_ratio = (float)width / (float)height;
    Image image(width, height);

    // Create simple scene with a camera and a sphere
    Scene scene;
    auto  camera  = Camera(Point3(-5.0f, 1.0f, 0.0f),
                         Point3(0.0f, 1.0f, 0.0f),
                         M_PI / 4,
                         aspect_ratio,
                         0);
    auto  sphere1 = Sphere(Point3(0.0f, 1.0f, 0.0f), 1.0f);
    scene.set_camera(camera);
    scene.add_object(&sphere1);

    // Run raytracer and save output image
    Renderer::run(image, scene);
    image.save("out.ppm");

    return 0;
}