#pragma once

#include "abstract_drawer.h"
#include "base_visitor.h"
#include <memory>

#include <vector>
#include "point.h"
#include "edge.h"
#include "carcass_model.h"
#include "camera.h"
#include "composite.h"

class DrawVisitor {
public:
    DrawVisitor(): camera(nullptr) {};
    DrawVisitor(std::shared_ptr<Camera> camera, std::shared_ptr<AbstractDrawer> drawer):
        camera(camera),
        drawer(drawer)
    {};
    ~DrawVisitor() = default;
    void visit(BaseModel &model) {}
    void visit(CarcassModel &model);
    void visit(Camera &camera);
    void visit(Composite &composite);
private:
    double convertDegreesToRadians(const double &degrees);
    Point projectPointOnCamera(
            const std::shared_ptr<Camera> camera,
            const Point &point,
            const MoveParams &modelPos,
            const RotateParams &modelRot,
            const ScaleParams &modelSc
    );
    std::shared_ptr<Camera> camera;
    std::shared_ptr<AbstractDrawer> drawer;
};
