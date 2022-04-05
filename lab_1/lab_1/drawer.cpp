#include "drawer.h"

void drawer_draw_line(drawer_t &drawer, double x1, double y1, double x2, double y2) {
    drawer.scene->addLine(x1, y1, x2, y2);
}

void drawer_clear(drawer_t &drawer) {
    drawer.scene->clear();
}
