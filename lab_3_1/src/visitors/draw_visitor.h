#pragma once

#include "abstract_drawer.h"
#include "base_visitor.h"
#include <memory>

#include "vector.h"
#include "point.h"
#include "edge.h"
#include "base_model.h"
#include "camera.h"

class DrawVisitor: public BaseVisitor {
public:
    DrawVisitor(): _camera(nullptr) {};
    DrawVisitor(std::shared_ptr<Camera> camera, std::shared_ptr<AbstractDrawer> drawer):
        _camera(camera),
        _drawer(drawer)
    {};
    ~DrawVisitor() = default;
    void visit(BaseModel &model) override;
    void visit(Camera &camera) override;
    void visit(Composite &composite) override;
private:
    double convertDegreesToRadians(const double &degrees);
    Point projectPointOnCamera(
            const std::shared_ptr<Camera> camera,
            const Point &point,
            const MoveParams &modelPos,
            const RotateParams &modelRot,
            const ScaleParams &modelSc
    );
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<AbstractDrawer> _drawer;
};
