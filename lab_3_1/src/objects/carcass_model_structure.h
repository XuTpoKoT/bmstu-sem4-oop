#pragma once

#include "vector.h"
#include "point.h"
#include "edge.h"
#include <string>

class CarcassModelStructure {
public:
    const Vector<Point> &getPoints();
    const Vector<Edge> &getLinks();

    bool setPoints(const Vector<Point> &points);
    bool setLinks(const Vector<Edge> &links);
private:
    Vector<Point> _points;
    Vector<Edge> _links;
};
