#include "base_model.h"

const Vector<Point> &CarcassModelStructure::getPoints() {
    return _points;
}
const Vector<Edge> &CarcassModelStructure::getLinks() {
    return _links;
}

bool CarcassModelStructure::setPoints(const Vector<Point> &points) {
    _points = points;
    return true;
}
bool CarcassModelStructure::setLinks(const Vector<Edge> &links) {
    _links = links;
    return true;
}
