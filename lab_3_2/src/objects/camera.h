#pragma once

#include "invisible_object.h"
#include "point.h"
#include "draw_visitor.h"

class Camera: public InvisibleObject {
public:
    friend class DrawVisitor; // сделать на метод
    Camera();
    ~Camera() = default;

    void accept(std::shared_ptr<BaseVisitor> visitor) override;
};
