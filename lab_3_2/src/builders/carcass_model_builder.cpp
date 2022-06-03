#pragma once

#include "carcass_model_builder.h"

CarcassModelBuilder::CarcassModelBuilder() {
}

void CarcassModelBuilder::buildPoints(const std::vector<Point> &points) {
    model.points = points;
}

void CarcassModelBuilder::buildEdges(const std::vector<Edge> &edges) {
    model.edges = edges;
}

void CarcassModelBuilder::reset() {
    model = CarcassModel();
}

BaseModel CarcassModelBuilder::getModel() {
    return model;
};
