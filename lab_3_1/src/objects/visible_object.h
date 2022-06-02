#pragma once

#include "object.h"

class VisibleObject: public Object {
public:
    VisibleObject() = default;
    explicit VisibleObject(const MoveParams &moveParams, const RotateParams &rotateParams, const ScaleParams &scaleParams):
        Object(moveParams, rotateParams, scaleParams)
    {};
    ~VisibleObject() = default;
    bool isVisible() const override {return true;};
};
