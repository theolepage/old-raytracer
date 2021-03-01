#pragma once

#include "image.hxx"
#include "scene.hxx"

namespace raytracer
{
class Renderer
{
  public:
    explicit Renderer(const Scene& scene,
                      Image&       image,
                      uint         nb_max_iterations = 3);

    void run();

  private:
    const Scene& scene_;
    Image&       image_;
    uint         nb_max_iterations_;

    Color
    compute_light_at(const Ray& ray, float t, const Object* object, uint level);
};

Renderer::Renderer(const Scene& scene, Image& image, uint nb_max_iterations)
    : scene_(scene)
    , image_(image)
    , nb_max_iterations_(nb_max_iterations)
{
}

Color Renderer::compute_light_at(const Ray&    ray,
                                 float         t,
                                 const Object* object,
                                 uint          level)
{
    if (level >= nb_max_iterations_)
        return Color(0, 0, 0);

    Point3 hitpoint = ray.at(t);
    Color  color    = scene_.get_ambient_color();

    for (uint l = 0; l < scene_.get_lights().size(); l++)
    {
        Light* light = scene_.get_lights().at(l);

        // Cast ray towards light
        Vector3 light_ray_dir = (light->get_pos() - hitpoint).normalize();
        Ray     light_ray(hitpoint, light_ray_dir);

        // Handle shadows
        bool shadow = false;
        for (uint o = 0; o < scene_.get_objects().size(); o++)
        {
            Object* object_ = scene_.get_objects().at(o);

            if (object == object_)
                break;

            std::optional<float> t_ = object_->intersect(light_ray);
            float dist = (object_->get_pos() - light->get_pos()).norm();

            if (t_.has_value() && t_.value() < dist)
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

        // Compute reflected components
        Ray     reflected_ray(object->get_pos(), reflected_ray_dir);
        float   closest_t      = Ray::RAY_MAX_DISTANCE;
        Object* closest_object = nullptr;
        for (uint o = 0; o < scene_.get_objects().size(); o++)
        {
            Object* object_ = scene_.get_objects().at(o);

            if (object == object_)
                break;

            std::optional<float> t_ = object_->intersect(reflected_ray);

            if (t_.has_value() && t_.value() < closest_t)
            {
                closest_t      = t_.value();
                closest_object = object_;
            }
        }
        if (closest_object)
            color += compute_light_at(
                         reflected_ray, closest_t, closest_object, level + 1) *
                     tp.k_s;
    }

    return color;
}

void Renderer::run()
{
    for (uint x = 0; x < image_.get_width(); x++)
    {
        for (uint y = 0; y < image_.get_height(); y++)
        {
            Vector3 point(2.0f * x / image_.get_width() - 1,
                          2.0f * y / image_.get_height() - 1,
                          0);

            Ray ray = scene_.get_camera().create_ray(point);

            for (uint o = 0; o < scene_.get_objects().size(); o++)
            {
                Object*              object = scene_.get_objects().at(o);
                std::optional<float> t      = object->intersect(ray);

                if (t.has_value())
                {
                    Color c = compute_light_at(ray, t.value(), object, 0);
                    image_.set_pixel(x, y, c.clamp());
                }
            }
        }
    }
}

} // namespace raytracer