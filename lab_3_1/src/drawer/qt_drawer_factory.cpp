#include "qt_drawer.h"
#include "qt_drawer_factory.h"

std::shared_ptr<AbstractDrawer> QtDrawerFactory::createDrawer() const {
    return std::make_shared<QtDrawer>(_scene, _color);
}
