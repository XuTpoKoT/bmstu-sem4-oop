#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsView>

#include "figure.h"

typedef QGraphicsScene scene_t;

void draw_figure(scene_t *scene, const struct figure_t &figure);

#endif // DRAWER_H
