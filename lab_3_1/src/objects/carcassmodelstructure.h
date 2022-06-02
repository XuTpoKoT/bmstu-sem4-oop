#ifndef CARCASSMODELSTRUCTURE_H
#define CARCASSMODELSTRUCTURE_H

#include "basemodelstructure.h"
#include "edge.h"
#include "point.h"
#include <vector>

class CarcassModelStructure : BaseModelStructure {
public:
    CarcassModelStructure();
    CarcassModelStructure(std::vector<Point>& Points, std::vector<Edge>& edges);
    ~CarcassModelStructure() = default;

    void addPoint(const Point& Point);
    void addEdge(const Edge& edge);
    const std::vector<Point>& getPoints() const;
    const std::vector<Edge>& getEdges() const;

private:
    std::vector<Point> Points;
    std::vector<Edge> edges;
};

#endif // CARCASSMODELSTRUCTURE_H
