#pragma once

#include "image.hxx"
#include "scene.hxx"

namespace raytracer
{
class Renderer
{
  public:
    static void run(Image& image, const Scene& scene);
};

void Renderer::run(Image& image, const Scene& scene)
{
    for (uint x = 0; x < image.get_width(); x++)
    {
        for (uint y = 0; y < image.get_height(); y++)
        {
            Vector3 point(2.0f * x / image.get_width() - 1,
                          2.0f * y / image.get_height() - 1,
                          0);

            Ray ray = scene.get_camera().create_ray(point);

            for (uint i = 0; i < scene.get_objects().size(); i++)
            {
                if (scene.get_objects().at(i)->intersect(ray).has_value())
                {
                    image.set_pixel(x, y, Color(100, 100, 255));

                    // DIFFUSE
                    // for each light in scene
                    // Id = kd * c * dot(normal surface, ray to light) *
                    // intensity of light

                    // SPECULAIRE
                    // send ray with opposite angle of the one between normal
                    // and camera ray
                    // Is = ks * itensity light * dot(S, light ray)^ns
                }
            }
        }
    }
}

} // namespace raytracer