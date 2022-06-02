#pragma once

#include "model_builder.h"

ModelBuilder::ModelBuilder() {
    _modelImpl = std::make_shared<Model>();
}

void ModelBuilder::buildPoints(const Vector<Point> &points) {
    _modelImpl->setPoints(points);
}

void ModelBuilder::buildLinks(const Vector<Edge> &links) {
    _modelImpl->setLinks(links);
}

void ModelBuilder::reset() {
    _modelImpl.reset();
    _modelImpl = std::shared_ptr<Model>(new Model());
}
