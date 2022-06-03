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
    std::vector<Point> points = model.structure->getPoints();
    std::vector<Edge> lines = model.structure->getLinks();
    for (auto line: lines) {
        auto p1 = projectPointOnCamera(
            _camera,
            points[line.getIndex1()],
            model.getPosition(),
            model.getRotation(),
            model.getScale()
        );
        auto p2 = projectPointOnCamera(
            _camera,
            points[line.getIndex2()],
            model.getPosition(),
            model.getRotation(),
            model.getScale()
        );
        _drawer->drawLine(p1, p2);
    }
}

void DrawVisitor::visit(Composite &composite) {}

void DrawVisitor::visit(Camera &camera) {}
