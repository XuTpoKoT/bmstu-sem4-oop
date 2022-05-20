#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include "edge.h"
#include "vertice.h"
#include <vector>

class ModelStructure {
public:
    ModelStructure() = default;
    ModelStructure(std::vector<Vertice>& vertices, std::vector<Edge>& edges);
    ModelStructure(Vertice& center, std::vector<Vertice>& vertices, std::vector<Edge>& edges);

    ~ModelStructure() = default;

    void add_vertice(const Vertice& vertice);
    void add_edge(const Edge& edge);
    const Vertice get_center() const;
    const std::vector<Vertice>& get_vertices() const;
    const std::vector<Edge>& get_edges() const;

    void transform(const Vertice& move, const Vertice& scale, const Vertice& rotate);

private:
    Vertice _center;

    std::vector<Vertice> _vertices;
    std::vector<Edge> _edges;
};

#endif // MODELSTRUCTURE_H
