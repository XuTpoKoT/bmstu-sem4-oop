#include "scene_manager.h"

SceneManager::SceneManager()
    : _scene(std::make_shared<Scene>())
{
}

std::shared_ptr<Scene> SceneManager::get_scene() const
{
    return _scene;
}

std::shared_ptr<Camera> SceneManager::get_camera() const
{
    return _current_camera;
}

void SceneManager::set_scene(std::shared_ptr<Scene> scene)
{
    _scene = std::move(scene);
}

void SceneManager::set_camera(const std::size_t& numb)
{
    _current_camera = std::dynamic_pointer_cast<Camera>(*_scene->get_object(numb));
}
