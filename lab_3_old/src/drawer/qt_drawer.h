#pragma once

#include <QPen>
#include <QColor>
#include <QGraphicsScene>
#include "abstract_drawer.h"

class QtDrawer: public AbstractDrawer {
public:
    explicit QtDrawer(
            std::shared_ptr<QGraphicsScene> scene
    ): scene(scene), pen(QPen(Qt::black)) {};
    QtDrawer(const QtDrawer &other) {scene = other.scene; };
    QtDrawer(QtDrawer &&other) {scene = other.scene; other.~QtDrawer();};
    ~QtDrawer() = default;
    void clear() override;
    void drawLine(const Point &p1, const Point &p2) const override;
private:
    std::shared_ptr<QGraphicsScene> scene;
    QPen pen;
};
