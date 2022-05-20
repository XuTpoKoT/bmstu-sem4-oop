#include "model_builder.h"

bool ModelBuilder::is_build() const
{
    return nullptr != _model_ptr;
}

void ModelBuilder::build()
{
    _model_ptr = std::make_shared<ModelStructure>();
}

void ModelBuilder::build_point(const double& x, const double& y, const double& z)
{
    if (!is_build()) { }

    Vertice pt_obj(x, y, z);
    _model_ptr->add_vertice(pt_obj);
}

void ModelBuilder::build_edge(const std::size_t& pt1, const std::size_t& pt2)
{
    if (!is_build()) { }

    Edge edge_obj(pt1, pt2);
    _model_ptr->add_edge(edge_obj);
}

std::shared_ptr<Model> ModelBuilder::get()
{
    return std::make_shared<Model>(Model(_model_ptr));
}
