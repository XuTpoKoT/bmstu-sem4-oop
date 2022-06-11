#include "object.h"

void Object::init() {
    moveParams = {0, 0, 0};
    rotateParams = {0, 0, 0};
    scaleParams = {1, 1, 1};
}

Object::Object() {
    init();
    id = nextId++;
}

//Object::~Object() {
//}

void Object::move(const MoveParams &moveParams) {
    this->moveParams.dx += moveParams.dx;
    this->moveParams.dy += moveParams.dy;
    this->moveParams.dz += moveParams.dz;
}

void Object::rotate(const RotateParams &rotateParams) {
    this->rotateParams.ox += rotateParams.ox;
    this->rotateParams.oy += rotateParams.oy;
    this->rotateParams.oz += rotateParams.oz;
}

void Object::scale(const ScaleParams &scaleParams) {
    this->scaleParams.kx *= scaleParams.kx;
    this->scaleParams.ky *= scaleParams.ky;
    this->scaleParams.kz *= scaleParams.kz;
}
