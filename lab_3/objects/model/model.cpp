#include "model.h"

#include <memory>

Model::Model(const Model& model)
    : _structure(model.get_structure())
{
}

void Model::transform(const Vertice& move, const Vertice& scale, const Vertice& rotate)
{
    _structure->transform(move, scale, rotate);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

Vertice Model::get_center() const
{
    return _structure->get_center();
}
