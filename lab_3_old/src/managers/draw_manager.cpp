#pragma once

#include "draw_manager.h"

void DrawManager::setDrawer(std::shared_ptr<AbstractDrawer> drawer) {
    this->drawer = drawer;
}

void DrawManager::drawScene() {
    if (currentCamera == nullptr || currentModel == nullptr)
        return;
    drawer->clear();
    // DrawVisitor visitor(currentCamera, drawer);
    // visitor.reset(new DrawVisitor(currentCamera, drawer));
    // currentModel->accept(visitor); // std::make_shared<DrawVisitor>
}

Point DrawManager::projectPointOnCamera(
    const std::shared_ptr<Camera> camera,
    const Point &point,
    const MoveParams &modelPos,
    const RotateParams &modelRot,
    const ScaleParams &modelSc
) {
    MoveParams camPos = camera->getPosition();
    RotateParams camRot = camera->getRotation();
    Point buffPoint(point);
    MoveParams moveCameraParams = {-camPos.dx, -camPos.dy, 0};

    buffPoint.rotate(modelRot.ox, modelRot.oy, modelRot.oz);
    buffPoint.rotate(camRot.ox, camRot.oy, camRot.oz);
    buffPoint.scale(modelSc.kx, modelSc.ky, modelSc.kz);

    buffPoint.move(modelPos.dx, modelPos.dy, modelPos.dz);
    buffPoint.move(moveCameraParams.dx, moveCameraParams.dy, moveCameraParams.dz);

    double eps = 1e-10;
    double denom = buffPoint.getZ() + camPos.dz;
    if (denom < eps && denom > -eps)
        denom = eps;
    double distCoef = camPos.dz / denom;

    Point resPoint(
        buffPoint.getX() * distCoef,
        buffPoint.getY() * distCoef,
        buffPoint.getZ()
    );
    return resPoint;
}

void DrawManager::drawModel(std::shared_ptr<BaseModel> baseModel) {
    std::shared_ptr<CarcassModel> model = std::dynamic_pointer_cast<CarcassModel>(baseModel);
    for (auto edge: model->edges) {
        auto p1 = projectPointOnCamera(
            currentCamera,
            model->points[edge.getIndex1()],
            model->getPosition(),
            model->getRotation(),
            model->getScale()
        );
        auto p2 = projectPointOnCamera(
            currentCamera,
            model->points[edge.getIndex2()],
            model->getPosition(),
            model->getRotation(),
            model->getScale()
        );
        drawer->drawLine(p1, p2);
    }
}

void DrawManager::setCurrentCamera(std::shared_ptr<Object> camera) {
    currentCamera = std::dynamic_pointer_cast<Camera>(camera);
}

void DrawManager::setCurrentModel(std::shared_ptr<Object> model) {
    currentModel = std::dynamic_pointer_cast<BaseModel>(model);
}
