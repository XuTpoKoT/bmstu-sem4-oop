#pragma once

#include <vector>
#include "point.h"
#include "edge.h"
#include "base_model.h"

class BaseModelBuilder {
public:
    ~BaseModelBuilder() = default;
    virtual BaseModel getModel() = 0;
    virtual void reset() = 0;
    virtual void buildPoints(const std::vector<Point> &points) = 0;
    virtual void buildEdges(const std::vector<Edge> &edges) = 0;
};
