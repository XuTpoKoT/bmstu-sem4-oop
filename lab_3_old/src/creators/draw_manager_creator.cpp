#pragma once

#include "draw_manager_creator.h"

std::shared_ptr<DrawManager> DrawManagerCreator::createManager() {
    if (manager == nullptr)
        createInstance();
    return manager;
}

void DrawManagerCreator::createInstance() {
    std::shared_ptr<DrawManager> manager(new DrawManager());
    manager = manager;
}
