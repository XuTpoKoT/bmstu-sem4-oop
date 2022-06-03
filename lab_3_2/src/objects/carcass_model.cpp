#include "carcass_model.h"

CarcassModel::~CarcassModel() {}

CarcassModel::CarcassModel(std::vector<Point> points, std::vector<Edge> edges)
{
    this->points = points;
    this->edges = edges;
}
