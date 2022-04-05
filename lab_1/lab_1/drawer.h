#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsView>

typedef QGraphicsScene scene_t;

struct drawer_t {
    scene_t *scene;
};

void drawer_draw_line(drawer_t &drawer, double x1, double y1, double x2, double y2);
void drawer_clear(drawer_t &drawer);

#endif // DRAWER_H
