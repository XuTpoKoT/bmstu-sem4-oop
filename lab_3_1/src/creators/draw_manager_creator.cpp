#pragma once

#include "draw_manager_creator.h"

std::shared_ptr<DrawManager> DrawManagerCreator::createManager() {
    if (_manager == nullptr)
        createInstance();
    return _manager;
}

void DrawManagerCreator::createInstance() {
    std::shared_ptr<DrawManager> manager(new DrawManager());
    _manager = manager;
}
