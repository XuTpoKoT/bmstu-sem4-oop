#pragma once

#include "draw_manager.h"

void DrawManager::setDrawer(std::shared_ptr<AbstractDrawer> drawer) {
    this->drawer = drawer;
}

void DrawManager::drawScene() {
    if (currentCamera == nullptr || currentModel == nullptr)
        return;
    drawer->clear();
    std::shared_ptr<BaseVisitor> visitor;
    visitor.reset(new DrawVisitor(currentCamera, drawer));
    currentModel->accept(visitor);
}

void DrawManager::setCurrentCamera(std::shared_ptr<Object> camera) {
    currentCamera = std::dynamic_pointer_cast<Camera>(camera);
}

void DrawManager::setCurrentModel(std::shared_ptr<Object> model) {
    currentModel = std::dynamic_pointer_cast<BaseModel>(model);
}
