#include "drawer.h"

static void draw_line(scene_t *scene, const points_t &points, const link_t &link) {
    point_t p1 = points_get(points, link.p_ind1);
    point_t p2 = points_get(points, link.p_ind2);
    scene->addLine(p1.x, p1.y, p2.x, p2.y);
}

static void draw_lines(scene_t *scene, const points_t &points, const links_t &links) {
    for (size_t i = 0; i < links.count; i++) {
        draw_line(scene, points, links.data[i]);
    }
}

void draw_figure(scene_t *scene, const struct figure_t &figure) {
    scene->clear();
    draw_lines(scene, figure.points, figure.links);
}
