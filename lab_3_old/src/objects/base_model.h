#ifndef BASE_MODEL_H
#define BASE_MODEL_H

#include "visible_object.h"
// #include "draw_visitor.h"
// #include "draw_manager.h"

enum class ModelType {
    Carcass
};

class BaseModel : public VisibleObject {
public:
    // friend class DrawManager;
    virtual ~BaseModel() = default;
//    virtual MoveParams getPosition() override { return moveParams; };
//    virtual RotateParams getRotation() override { return rotateParams; };
//    virtual ScaleParams getScale() override { return scaleParams; };

    // virtual void accept(std::shared_ptr<DrawVisitor> visitor) override;
private:
    int f() { return 5; }
};

#endif
