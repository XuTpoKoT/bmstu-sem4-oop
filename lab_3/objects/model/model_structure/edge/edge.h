#ifndef EDGE_H
#define EDGE_H

#include <cstdlib>

class Edge {
public:
    Edge() = default;
    Edge(const size_t& first_i, const size_t& last_i);
    Edge(const Edge& _edge) = default;

    ~Edge() = default;

    size_t get_first_vertice() const;
    size_t get_last_vertice() const;

    void set_first_vertice(const size_t& i);
    void set_last_vertice(const size_t& i);

private:
    size_t _first_i;
    size_t _last_i;
};

#endif // EDGE_H
