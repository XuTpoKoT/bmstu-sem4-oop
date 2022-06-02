#pragma once

#include "base_manager.h"
#include "scene.h"

class SceneManager: public BaseManager {
public:
    SceneManager() {
        _scene = std::make_shared<Scene>();
    };
    ~SceneManager() = default;
    std::shared_ptr<Scene> getScene();
    void removeObject(const int id);
private:
    std::shared_ptr<Scene> _scene;
};
