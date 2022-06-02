#pragma once

#include "abstract_drawer_factory.h"
#include <QGraphicsScene>

class QtDrawerFactory: public AbstractDrawerFactory {
public:
    explicit QtDrawerFactory(std::shared_ptr<QGraphicsScene> scene, std::string color):
        _scene(scene),
        _color(color)
    {};
    ~QtDrawerFactory() = default;
    std::shared_ptr<AbstractDrawer> createDrawer() const override;
private:
    std::shared_ptr<QGraphicsScene> _scene;
    std::string _color;
};
