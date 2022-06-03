#pragma once

#include <QPen>
#include <QColor>
#include <QGraphicsScene>
#include "abstract_drawer.h"

class QtDrawer: public AbstractDrawer {
public:
    explicit QtDrawer(
            std::shared_ptr<QGraphicsScene> scene,
            std::string color
    ): _scene(scene), _pen(QPen(QColor(color.c_str()))) {};
    QtDrawer(const QtDrawer &other) {_scene = other._scene; };
    QtDrawer(QtDrawer &&other) {_scene = other._scene; other.~QtDrawer();};
    ~QtDrawer() = default;
    void clear() override;
    void drawLine(const Point &p1, const Point &p2) const override;
private:
    std::shared_ptr<QGraphicsScene> _scene;
    QPen _pen;
};
