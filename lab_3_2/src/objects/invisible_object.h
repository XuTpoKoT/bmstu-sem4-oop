#pragma once

#include "object.h"

class InvisibleObject: public Object {
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;
    bool isVisible() const override {return false;};
};
