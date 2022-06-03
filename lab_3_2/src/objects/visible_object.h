#pragma once

#include "object.h"

class VisibleObject: public Object {
public:
    VisibleObject() = default;
    ~VisibleObject() = default;
    bool isVisible() const override {return true;};
};
