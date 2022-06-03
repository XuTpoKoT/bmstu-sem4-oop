#include "qt_drawer.h"

void QtDrawer::drawLine(const Point &p1, const Point &p2) const {
    _scene->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(), _pen);
}

void QtDrawer::clear() {
    _scene->clear();
}
