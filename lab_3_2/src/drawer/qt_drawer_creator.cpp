#include "qt_drawer.h"
#include "qt_drawer_creator.h"

std::shared_ptr<AbstractDrawer> QtDrawerCreator::createDrawer() const {
    return std::make_shared<QtDrawer>(scene);
}
