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

    auto camera = Camera(Point3(-6.0f, 0.0f, 0.0f),
                         Point3(0.0f, 0.0f, 0.0f),
                         M_PI / 4,
                         aspect_ratio,
                         0);
    scene.set_camera(camera);

    auto light1 = Light(Point3(0.0f, -3.0f, 0.0f), Color(1.0f, 1.0f, 1.0f));
    scene.add_light(&light1);

    UniformTexture texture_green(Color(0.31f, 0.74f, 0.41f));

    auto sphere1 = Sphere(Point3(0.0f, -1.0f, 3.0f), 1.0f);
    auto sphere2 = Sphere(Point3(0.0f, -1.0f, -3.0f), 0.6f);
    auto sphere3 = Sphere(Point3(0.0f, 2.0f, 0.0f), 0.8f);
    sphere3.set_texture(&texture_green);
    scene.add_object(&sphere1);
    scene.add_object(&sphere2);
    scene.add_object(&sphere3);

    // Run raytracer and save output image
    Renderer::run(image, scene);
    image.save("out.ppm");

    return 0;
}