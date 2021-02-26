#pragma once

#include "camera.hxx"
#include "light.hxx"
#include "object.hxx"

namespace raytracer
{
class Scene
{
  public:
    explicit Scene();

    virtual ~Scene() = default;

    const Camera&               get_camera() const;
    const std::vector<Object*>& get_objects() const;
    const std::vector<Light*>&  get_lights() const;
    const Color                 get_ambient_color() const;

    void set_camera(const Camera& camera);

    void add_object(Object* object);
    void add_light(Light* light);

  private:
    std::vector<Object*> objects_;
    std::vector<Light*>  lights_;
    Camera               camera_;
    Color                ambient_color_;
};

Scene::Scene()
    : ambient_color_(0.05f, 0.05f, 0.05f)
{
}

const Camera& Scene::get_camera() const { return camera_; }

const std::vector<Object*>& Scene::get_objects() const { return objects_; }

const std::vector<Light*>& Scene::get_lights() const { return lights_; }

const Color Scene::get_ambient_color() const { return ambient_color_; }

void Scene::set_camera(const Camera& camera) { camera_ = camera; }

void Scene::add_object(Object* object) { objects_.push_back(object); }

void Scene::add_light(Light* light) { lights_.push_back(light); }

} // namespace raytracer