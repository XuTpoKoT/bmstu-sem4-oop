#ifndef EDGE_H
#define EDGE_H

#include <cstdlib>

class Edge {
public:
    Edge() = default;
    Edge(size_t index1, size_t index2);
    Edge(const Edge& edge) = default;

    ~Edge() = default;

    size_t getIndex1() const;
    size_t getIndex2() const;

    void setIndex1(size_t index);
    void setIndex2(size_t index);

private:
    size_t index1;
    size_t index2;
};

#endif // EDGE_H
