#pragma once

#include "carcass_model_builder.h"

class ModelDirector {
public:
    ModelDirector(std::shared_ptr<CarcassModelBuilder> builder);
    ~ModelDirector() = default;
    BaseModel buildModel(const std::vector<Point> &points, const std::vector<Edge> &edges);
protected:
    std::shared_ptr<CarcassModelBuilder> builder;
};
