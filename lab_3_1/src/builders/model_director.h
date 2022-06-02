#pragma once

#include "base_model_director.h"
#include "model_builder.h"

class ModelDirector: public BaseModelDirector {
public:
    ModelDirector();
    ~ModelDirector() = default;
    std::shared_ptr<BaseModel> buildModel(const Vector<Point> &points, const Vector<Edge> &edges);
};
