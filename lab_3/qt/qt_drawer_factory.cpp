#include "qt_drawer_factory.h"

QtDrawerFactory::QtDrawerFactory(QGraphicsScene* scene)
    : _scene(scene)
{
}

std::unique_ptr<AbstractDrawer> QtDrawerFactory::create_drawer()

{
    return std::unique_ptr<AbstractDrawer>(new QtDrawer(_scene));
}
