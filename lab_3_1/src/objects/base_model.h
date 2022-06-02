#pragma once

#include "base_model_structure.h"
#include "visible_object.h"
#include "carcass_model_structure.h"
#include "draw_visitor.h"

class BaseModel : public VisibleObject {
    friend class DrawVisitor; // method
public:
    virtual ~BaseModel() = 0;
    // virtual void scale(double kx, double ky, double kz);
//    const std::shared_ptr<BaseModelStructure> getStructure() const { return structure; };

//protected:
//    std::shared_ptr<BaseModelStructure> structure;
};
