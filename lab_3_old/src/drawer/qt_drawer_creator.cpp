#include "qt_drawer.h"
#include "qt_drawer_creator.h"

std::shared_ptr<AbstractDrawer> QtDrawerCreator::createDrawer() const {
    auto drawer = QtDrawer(scene);
    return std::make_shared<QtDrawer>(drawer);
}
