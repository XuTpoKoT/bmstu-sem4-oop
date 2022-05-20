#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "base_builder.h"
#include "model.h"

class ModelBuilder : public BaseBuilder {
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    bool is_build() const override;
    void build() override;
    void build_point(const double& x, const double& y, const double& z);
    void build_edge(const std::size_t& pt1, const std::size_t& pt2);

    std::shared_ptr<Model> get();

private:
    std::shared_ptr<ModelStructure> _model_ptr;
};
#endif // MODELBUILDER_H
