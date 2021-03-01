#pragma once

#include "image.hxx"
#include "scene.hxx"

namespace raytracer
{
class Renderer
{
  public:
    static void run(Image& image, const Scene& scene);

  private:
    static Color compute_light_at(const Scene&  scene,
                                  const Ray&    ray,
                                  float         t,
                                  const Object* object);
};

Color Renderer::compute_light_at(const Scene&  scene,
                                 const Ray&    ray,
                                 float         t,
                                 const Object* object)
{
    Point3 hitpoint = ray.at(t);
    Color  color    = scene.get_ambient_color();

    for (uint l = 0; l < scene.get_lights().size(); l++)
    {
        Light* light = scene.get_lights().at(l);

        // Cast ray towards light
        Vector3 light_ray_dir = (light->get_pos() - hitpoint).normalize();
        Ray     light_ray(hitpoint, light_ray_dir);

        // Handle shadows
        bool shadow = false;
        for (uint o = 0; o < scene.get_objects().size(); o++)
        {
            Object* object_ = scene.get_objects().at(o);

            if (object == object_)
                break;

            std::optional<float> t = object_->intersect(light_ray);
            float dist = (object_->get_pos() - light->get_pos()).norm();

            if (t.has_value() && t.value() < dist)
                shadow |= true;
        }
        if (shadow)
            break;

        // Compute diffuse component
        Color         li = light->get_color();
        TextureParams tp = object->get_texture_params(hitpoint);

        float d = dot(object->get_surface_normal(hitpoint), light_ray_dir);

        color += li * tp.color * tp.k_d * (1 - d);

        // Compute specular component
        Vector3 n                 = object->get_surface_normal(hitpoint);
        Vector3 v                 = ray.get_direction().normalize();
        Vector3 reflected_ray_dir = v - n * 2 * dot(v, n);

        float d2 = dot(reflected_ray_dir, light_ray_dir);

        color += li * std::pow(d2, tp.n_s) * tp.k_s;
    }

    return color;
}

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
                    Color c = compute_light_at(scene, ray, t.value(), object);
                    image.set_pixel(x, y, c.clamp());
                }
            }
        }
    }
}

} // namespace raytracer