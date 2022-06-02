#include "scene_manager.h"

std::shared_ptr<Scene> SceneManager::getScene() {
    return _scene;
}

void SceneManager::removeObject(const int id) {
    auto iter = _scene->getObject(id);
    _scene->removeObject(iter);
}
