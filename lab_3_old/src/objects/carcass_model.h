#ifndef CARCASS_MODEL_H
#define CARCASS_MODEL_H

#include "base_model.h"
#include "edge.h"
// #include "carcass_model_builder.h"

class CarcassModelBuilder;
class DrawManager;

class CarcassModel : public BaseModel {
    friend class CarcassModelBuilder;
    // friend class DrawVisitor;
    friend class DrawManager;
public:
    ~CarcassModel();
//    virtual MoveParams getPosition() override { return moveParams; };
//    virtual RotateParams getRotation() override { return rotateParams; };
//    virtual ScaleParams getScale() override { return scaleParams; };

    // virtual void accept(std::shared_ptr<DrawVisitor> visitor) override;
protected:
    CarcassModel();
    std::vector<Point> points;
    std::vector<Edge> edges;
};

#endif // CARCASS_MODEL_H
