#pragma once

#include <string>
#include "vector.h"
#include "edge.h"
#include "point.h"
#include "base_model.h"
#include "base_model_builder.h"

class BaseModelDirector {
public:
    ~BaseModelDirector() = default;
    // virtual std::shared_ptr<BaseModel> buildModel(const Vector<Point> &points, const Vector<Edge> &edges) = 0;
//protected:
//    std::shared_ptr<BaseModelBuilder> _builder;
};
