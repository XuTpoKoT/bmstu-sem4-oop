#pragma once

#include "object.h"

class InvisibleObject: public Object {
public:
    InvisibleObject() = default;
    explicit InvisibleObject(const MoveParams &moveParams, const RotateParams &rotateParams, const ScaleParams &scaleParams):
        Object(moveParams, rotateParams, scaleParams)
    {};
    ~InvisibleObject() = default;
    bool isVisible() const override {return false;};
};
