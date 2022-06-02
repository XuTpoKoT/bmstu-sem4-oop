#pragma once

#include "carcass_model_director.h"

CarcassModelDirector::CarcassModelDirector() {
    _builder.reset(new CarcassModelBuilder);
}

std::shared_ptr<CarcassModel> CarcassModelDirector::buildModel(const Vector<Point> &points, const Vector<Edge> &edges) {
    _builder->buildPoints(points);
    _builder->buildLinks(edges);
    return _builder->getModel();
}
