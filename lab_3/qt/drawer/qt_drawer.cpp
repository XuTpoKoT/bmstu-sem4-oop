#include "qt_drawer.h"

QtDrawer::QtDrawer(QGraphicsScene* scene)
    : _scene(scene)
{
}

QtDrawer::QtDrawer(const QtDrawer& drawer)
    : _scene(drawer._scene)
{
}

void QtDrawer::clear_scene()
{
    _scene->clear();
}

void QtDrawer::draw_line(const Vertice& v1, const Vertice& v2)
{
    _scene->addLine(v1.get_x(), v1.get_y(), v2.get_x(), v2.get_y());
}
