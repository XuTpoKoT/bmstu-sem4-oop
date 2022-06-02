#pragma once

#include "draw_manager.h"

void DrawManager::setDrawer(std::shared_ptr<AbstractDrawer> drawer) {
    _drawer = drawer;
}

void DrawManager::drawScene() {
    if (_currentCamera == nullptr || _currentModel == nullptr)
        return;
    _drawer->clear();
    std::shared_ptr<BaseVisitor> visitor;
    visitor.reset(new DrawVisitor(_currentCamera, _drawer));
    _currentModel->accept(visitor);
}

void DrawManager::setCurrentCamera(std::shared_ptr<Object> camera) {
    _currentCamera = std::dynamic_pointer_cast<Camera>(camera);
}

void DrawManager::setCurrentModel(std::shared_ptr<Object> model) {
    _currentModel = std::dynamic_pointer_cast<BaseModel>(model);
}
