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

            for (uint o = 0; o < scene.get_objects().size(); o++)
            {
                Object*              object = scene.get_objects().at(o);
                std::optional<float> t      = object->intersect(ray);

                if (t.has_value())
                {
                    Point3 hitpoint = ray.at(t.value());
                    Color  color    = scene.get_ambient_color();
                    // FIXME: use scene.get_ambient_color()

                    for (uint l = 0; l < scene.get_lights().size(); l++)
                    {
                        Light* light = scene.get_lights().at(l);

                        // Cast ray towards light
                        Vector3 light_ray_dir =
                            (light->get_pos() - hitpoint).normalize();
                        Ray light_ray(hitpoint, light_ray_dir);

                        // FIXME: If intersect with object => break

                        // Compute diffuse component
                        Color         li = light->get_color();
                        TextureParams tp = object->get_texture_params(hitpoint);

                        float d = dot(object->get_surface_normal(hitpoint),
                                      light_ray_dir);

                        color += li * tp.color * tp.k_d * (1 - d);

                        // Compute specular component
                        Vector3 n = object->get_surface_normal(hitpoint);
                        Vector3 v = ray.get_direction().normalize();
                        Vector3 reflected_ray_dir = v - n * 2 * dot(v, n);

                        float d2 = dot(reflected_ray_dir, light_ray_dir);

                        color += li * std::pow(d2, tp.n_s) * tp.k_s;
                    }

                    image.set_pixel(x, y, color.clamp());

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