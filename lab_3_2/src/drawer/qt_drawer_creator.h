#pragma once

#include "abstract_drawer_creator.h"
#include <QGraphicsScene>

class QtDrawerCreator: public AbstractDrawerCreator {
public:
    explicit QtDrawerCreator(std::shared_ptr<QGraphicsScene> scene):
        scene(scene)
    {};
    ~QtDrawerCreator() = default;
    std::shared_ptr<AbstractDrawer> createDrawer() const override;
private:
    std::shared_ptr<QGraphicsScene> scene;
};
