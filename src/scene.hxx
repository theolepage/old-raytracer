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

    void set_camera(const Camera& camera);

    void add_object(Object* object);

  private:
    std::vector<Object*> objects_;
    std::vector<Light>   lights_;
    Camera               camera_;
};

Scene::Scene() {}

const Camera& Scene::get_camera() const { return camera_; }

const std::vector<Object*>& Scene::get_objects() const { return objects_; }

void Scene::set_camera(const Camera& camera) { camera_ = camera; }

void Scene::add_object(Object* object) { objects_.push_back(object); }

} // namespace raytracer