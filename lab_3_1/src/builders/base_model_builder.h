#pragma once

#include "vector.h"
#include "point.h"
#include "edge.h"
#include "model.h"
#include "base_model.h"

class BaseModelBuilder {
public:
    ~BaseModelBuilder() = default;
    std::shared_ptr<BaseModel> getModel() {
        return std::make_shared<BaseModel>(_modelImpl);
    };
    virtual void buildPoints(const Vector<Point> &points) = 0;
    virtual void buildLinks(const Vector<Edge> &links) = 0;
    virtual void reset() = 0;
protected:
    std::shared_ptr<Model> _modelImpl;
};
