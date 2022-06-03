#include "transform_manager.h"

void TransformManager::moveObject(std::shared_ptr<Object> obj, const MoveParams &move) {
    obj->move(move);
}

void TransformManager::rotateObject(std::shared_ptr<Object> obj, const RotateParams &rotate) {
    obj->rotate(rotate);
}

void TransformManager::scaleObject(std::shared_ptr<Object> obj, const ScaleParams &scale) {
    obj->scale(scale);
}
