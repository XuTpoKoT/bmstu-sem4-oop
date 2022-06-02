#pragma once

#include "base_model_director.h"
#include "carcass_model_builder.h"
#include "carcass_model.h"

class CarcassModelDirector: public BaseModelDirector {
public:
    CarcassModelDirector();
    ~CarcassModelDirector() = default;
    std::shared_ptr<CarcassModel> buildModel(const Vector<Point> &points, const Vector<Edge> &edges);
protected:
    std::shared_ptr<CarcassModelBuilder> _builder;
};
