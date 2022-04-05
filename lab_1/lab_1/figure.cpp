#include <iostream>

#include "figure.h"

figure_t& figure_init() {
    static figure_t figure;
    points_init(figure.points);
    links_init(figure.links);
    return figure;
}

err_t figure_load(figure_t &figure, const char *filename) {
    err_t rc = OK;
    figure_t buf_figure;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        rc = FILE_OPEN_ERR;

    if (rc == OK) {
        rc = figure_read(buf_figure, f);
        fclose(f);
        if (rc == OK) {
            figure_free(figure);
            figure = buf_figure;
        }
    }

    return rc;
}

err_t figure_read(figure_t &figure, FILE *f) {
    err_t rc = OK;

    if (rc == OK)
        rc = points_create(figure.points, f);

    if (rc == OK) {
        rc = links_create(figure.links, f);
        if (rc != OK)
            points_free(figure.points);
    }

    return rc;
}

void figure_free(figure_t &figure) {
    points_free(figure.points);
    links_free(figure.links);
}

bool figure_is_correct(const figure_t &figure) {
    return points_are_correct(figure.points) && links_are_correct(figure.links);
}

err_t figure_move(figure_t &figure, const move_options_t &options) {
    return points_move(figure.points, figure.center, options);
}

err_t figure_scale(figure_t &figure, const scale_options_t &options) {
    return points_scale(figure.points, figure.center, options);
}

err_t figure_rotate(figure_t &figure, const rotate_options_t &options) {
    return points_rotate(figure.points, figure.center, options);
}

static void draw_line(drawer_t &drawer, const points_t &points, const link_t &link) {
    point_t p1 = points_get(points, link.p_ind1);
    point_t p2 = points_get(points, link.p_ind2);
    drawer_draw_line(drawer, p1.x, p1.y, p2.x, p2.y);
}

static void draw_lines(drawer_t &drawer, const points_t &points, const links_t &links) {
    for (size_t i = 0; i < links.count; i++) {
        draw_line(drawer, points, links.data[i]);
    }
}

err_t figure_draw(drawer_t &drawer, const struct figure_t &figure) {
    err_t rc = OK;
    if (figure_is_correct(figure)) {
        drawer_clear(drawer);
        draw_lines(drawer, figure.points, figure.links);
    }
    else
        rc = FIGURE_WAS_NOT_INIT_ERR;

    return rc;
}

