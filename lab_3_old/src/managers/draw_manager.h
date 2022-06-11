#pragma once

#include <memory>
#include "base_manager.h"
#include "point.h"
#include "camera.h"
#include "abstract_drawer.h"
#include "carcass_model.h"

#include "composite.h"

class Composite;
class Camera;
class Model;

class DrawManager: public BaseManager {
public:
    DrawManager():
        drawer(nullptr),
        currentCamera(nullptr),
        currentModel(nullptr)
    {};
    DrawManager(const DrawManager &other) {drawer = other.drawer;};
    ~DrawManager() = default;
    void setDrawer(std::shared_ptr<AbstractDrawer> drawer);
    void drawScene();
    // void drawModel(std::shared_ptr<BaseModel> model);
    void setCurrentCamera(std::shared_ptr<Object> camera);
    void setCurrentModel(std::shared_ptr<Object> model);
private:
    void drawModel(std::shared_ptr<BaseModel> model);
    double convertDegreesToRadians(const double &degrees);
    Point projectPointOnCamera(
            const std::shared_ptr<Camera> camera,
            const Point &point,
            const MoveParams &modelPos,
            const RotateParams &modelRot,
            const ScaleParams &modelSc
    );
    std::shared_ptr<AbstractDrawer> drawer;
    std::shared_ptr<Camera> currentCamera;
    std::shared_ptr<BaseModel> currentModel;
};
