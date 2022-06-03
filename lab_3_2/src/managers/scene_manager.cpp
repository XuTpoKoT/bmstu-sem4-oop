#include "scene_manager.h"

std::shared_ptr<Scene> SceneManager::getScene() {
    return scene;
}

void SceneManager::removeObject(const int id) {
    auto iter = scene->getObject(id);
    scene->removeObject(iter);
}
