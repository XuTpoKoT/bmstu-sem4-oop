#pragma once

#include "carcass_model_builder.h"

CarcassModelBuilder::CarcassModelBuilder() {
    structure = std::make_shared<CarcassModelStructure>();
}

void CarcassModelBuilder::buildPoints(const Vector<Point> &points) {
    structure->setPoints(points);
}

void CarcassModelBuilder::buildLinks(const Vector<Edge> &links) {
    structure->setLinks(links);
}

void CarcassModelBuilder::reset() {
    // structure.reset();
    structure = std::shared_ptr<CarcassModelStructure>(new CarcassModelStructure());
}
