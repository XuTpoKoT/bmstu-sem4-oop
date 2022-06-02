#pragma once

#include "scene_manager_creator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::createManager() {
    if (_manager == nullptr)
        createInstance();
    return _manager;
}

void SceneManagerCreator::createInstance() {
    std::shared_ptr<SceneManager> manager(new SceneManager());
    _manager = manager;
}
