#ifndef ABSTRACT_DRAWER_H
#define ABSTRACT_DRAWER_H

#include "vertice.h"

class AbstractDrawer {
public:
    AbstractDrawer() = default;

    virtual ~AbstractDrawer() = default;

    virtual void draw_line(const Vertice& v1, const Vertice& v2) = 0;
    virtual void clear_scene() = 0;
};

#endif // ABSTRACT_DRAWER_H
