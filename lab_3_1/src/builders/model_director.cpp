#pragma once

#include "model_director.h"

ModelDirector::ModelDirector() {
    _builder.reset(new ModelBuilder);
}

std::shared_ptr<BaseModel> ModelDirector::buildModel(const Vector<Point> &points, const Vector<Edge> &edges) {
    _builder->buildPoints(points);
    _builder->buildLinks(edges);
    return _builder->getModel();
}
