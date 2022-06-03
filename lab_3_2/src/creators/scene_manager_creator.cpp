#pragma once

#include "scene_manager_creator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::createManager() {
    if (manager == nullptr)
        createInstance();
    return manager;
}

void SceneManagerCreator::createInstance() {
    std::shared_ptr<SceneManager> manager(new SceneManager());
    manager = manager;
}
