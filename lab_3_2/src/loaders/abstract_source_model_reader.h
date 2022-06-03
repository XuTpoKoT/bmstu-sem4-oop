#pragma once

#include <vector>
#include "base_model.h"
#include "edge.h"
#include "point.h"

class AbstractSourceModelReader
{
public:
    ~AbstractSourceModelReader() = default;

    virtual void open(std::string source_name) = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    virtual ModelType readModelType() = 0;
    virtual std::vector<Point> readPoints() = 0;
    virtual std::vector<Edge> readEdges() = 0;
};
