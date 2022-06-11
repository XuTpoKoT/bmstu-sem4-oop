#include "camera.h"

Camera::Camera(): InvisibleObject() {
    moveParams = { 0, 0, 300 };
};

//Camera::Camera(const MoveParams &moveParams, const RotateParams &rotateParams, const ScaleParams &scaleParams) {
//    this->moveParams = moveParams;
//    this->rotateParams = rotateParams;
//    this->scaleParams = scaleParams;
//}

//void Camera::accept(std::shared_ptr<BaseVisitor> visitor) {
//    visitor->visit(*this);
//}
