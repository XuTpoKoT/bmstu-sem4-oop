#pragma once

#include "base_model_builder.h"

class ModelBuilder: public BaseModelBuilder {
public:
    ModelBuilder();
    ~ModelBuilder() = default;
    void buildPoints(const Vector<Point> &points) override;
    void buildLinks(const Vector<Edge> &links) override;
    void reset() override;
};
