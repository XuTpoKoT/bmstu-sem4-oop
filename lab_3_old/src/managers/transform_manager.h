#pragma once

#include "base_manager.h"
#include "object.h"

class TransformManager: public BaseManager {
public:
    TransformManager() = default;
    ~TransformManager() = default;
    void moveObject(std::shared_ptr<Object> obj, const MoveParams &move);
    void rotateObject(std::shared_ptr<Object> obj, const RotateParams &rotate);
    void scaleObject(std::shared_ptr<Object> obj, const ScaleParams &scale);
};
