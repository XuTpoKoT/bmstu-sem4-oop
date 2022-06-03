#pragma once

#include "base_model_builder.h"
#include "carcass_model.h"

class CarcassModelBuilder: public BaseModelBuilder {
public:
    CarcassModelBuilder();
    ~CarcassModelBuilder() = default;
    BaseModel getModel();
    void reset();
    void buildPoints(const std::vector<Point> &points);
    void buildEdges(const std::vector<Edge> &edges);
protected:
    CarcassModel model;
};
