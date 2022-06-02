#pragma once

#include <QGraphicsScene>
#include "point.h"
#include <memory>

class AbstractDrawer {
public:
    virtual ~AbstractDrawer() = default;
    virtual void clear() = 0;
    virtual void drawLine(const Point &p1, const Point &p2) const = 0;
};
