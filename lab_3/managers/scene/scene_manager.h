#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "base_manager.h"
#include "camera.h"
#include "scene.h"
#include <memory>

class SceneManager : public BaseManager {
public:
    SceneManager();
    SceneManager(const SceneManager&) = delete;

    ~SceneManager() = default;

    SceneManager& operator=(const SceneManager&) = delete;

    std::shared_ptr<Scene> get_scene() const;
    std::shared_ptr<Camera> get_camera() const;

    void set_scene(std::shared_ptr<Scene> scene);
    void set_camera(const size_t& numb);

private:
    std::shared_ptr<Scene> _scene;
    std::shared_ptr<Camera> _current_camera;
};

#endif // SCENEMANAGER_H
