#pragma once

#include "vector.h"
#include "edge.h"
#include "point.h"

class BaseLoader
{
public:
    ~BaseLoader() = default;

    virtual void open(std::string source_name) = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    virtual Vector<Point> readPoints() = 0;
    virtual Vector<Edge> readLinks() = 0;
};
