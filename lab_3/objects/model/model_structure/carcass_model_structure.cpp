#include "model_structure.h"

void ModelStructure::add_vertice(const Vertice& vertice)
{
    _vertices.push_back(vertice);
}

void ModelStructure::add_edge(const Edge& edge)
{
    _edges.push_back(edge);
}

const Vertice ModelStructure::get_center() const
{
    Vertice center = Vertice(0, 0, 0);

    for (const auto& element : _vertices)
        center = center + element;

    center = Vertice(center.get_x() / _vertices.size(), center.get_y() / _vertices.size(), center.get_z() / _vertices.size());

    return center;
}

const std::vector<Vertice>& ModelStructure::get_vertices() const
{
    return _vertices;
}

const std::vector<Edge>& ModelStructure::get_edges() const
{
    return _edges;
}

void ModelStructure::transform(const Vertice& move, const Vertice& scale, const Vertice& rotate)
{

    for (auto& pt : _vertices) {
        pt.move(move.get_x(), move.get_y(), move.get_z());
        pt.scale(scale.get_x(), scale.get_y(), scale.get_z());
        pt.rotate(rotate.get_x(), rotate.get_y(), rotate.get_z());
    }
}

ModelStructure::ModelStructure(std::vector<Vertice>& vertices, std::vector<Edge>& edges)
    : _center {}
    , _vertices(vertices)
    , _edges(edges)
{
}

ModelStructure::ModelStructure(Vertice& center, std::vector<Vertice>& vertices, std::vector<Edge>& edges)
    : _center(center)
    , _vertices(vertices)
    , _edges(edges)
{
}
