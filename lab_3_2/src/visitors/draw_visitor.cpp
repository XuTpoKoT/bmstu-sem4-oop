#include "draw_visitor.h"

Point DrawVisitor::projectPointOnCamera(
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

void DrawVisitor::visit(CarcassModel &model) {
    for (auto edge: model.edges) {
        auto p1 = projectPointOnCamera(
            camera,
            model.points[edge.getIndex1()],
            model.getPosition(),
            model.getRotation(),
            model.getScale()
        );
        auto p2 = projectPointOnCamera(
            camera,
            model.points[edge.getIndex2()],
            model.getPosition(),
            model.getRotation(),
            model.getScale()
        );
        drawer->drawLine(p1, p2);
    }
}

void DrawVisitor::visit(Composite &composite) {}

void DrawVisitor::visit(Camera &camera) {}
