#pragma once

#include "visible_object.h"
#include "draw_visitor.h"

enum class ModelType {
    Carcass
};

class BaseModel : public VisibleObject {
public:
    virtual ~BaseModel() = default;
    void accept(std::shared_ptr<BaseVisitor> visitor) override;
};
