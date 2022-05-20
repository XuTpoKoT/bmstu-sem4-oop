#include "edge.h"

#include <cstdlib>

Edge::Edge(const size_t& first_i, const size_t& last_i)
    : _first_i(first_i)
    , _last_i(last_i) {};

size_t Edge::get_first_vertice() const
{
    return _first_i;
}

size_t Edge::get_last_vertice() const
{
    return _last_i;
}

void Edge::set_first_vertice(const size_t& i)
{
    _first_i = i;
}

void Edge::set_last_vertice(const size_t& i)
{
    _last_i = i;
}
