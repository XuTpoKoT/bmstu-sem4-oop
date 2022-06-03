#pragma once

#include "visible_object.h"
#include "draw_visitor.h"

enum class ModelType {
    Carcass
};

class BaseModel : public VisibleObject {
    friend class DrawVisitor; // method
public:
    virtual ~BaseModel() = default;
};
