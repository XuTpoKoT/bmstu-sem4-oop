#pragma once

#include "model_director.h"

ModelDirector::ModelDirector(std::shared_ptr<CarcassModelBuilder> builder) :
    builder(builder){
}

BaseModel ModelDirector::buildModel(const std::vector<Point> &points, const std::vector<Edge> &edges) {
    builder->reset();
    builder->buildPoints(points);
    builder->buildEdges(edges);
    return builder->getModel();
}
