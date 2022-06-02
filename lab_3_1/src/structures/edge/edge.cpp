#include "edge.h"

#include <cstdlib>

Edge::Edge(size_t index1, size_t index2)
    : index1(index1)
    , index2(index2) {};

size_t Edge::getIndex1() const
{
    return index1;
}

size_t Edge::getIndex2() const
{
    return index2;
}

void Edge::setIndex1(size_t index)
{
    index1 = index;
}

void Edge::setIndex2(size_t index)
{
    index2 = index;
}
