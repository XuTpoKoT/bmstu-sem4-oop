#ifndef FIGURE_H
#define FIGURE_H

#include "points.h"
#include "links.h"
#include "drawer.h"
#include "err.h"

struct figure_t
{
    points_t points;
    links_t links;
    point_t center;
};

figure_t& figure_init();
err_t figure_load(figure_t &figure, const char *filename);
err_t figure_read(figure_t &figure, FILE *f);
void figure_free(figure_t &figure);
// err_t figure_create_copy(figure_t &dst, const figure_t &src);

void figure_move(figure_t &figure, const move_options_t &options);
void figure_scale(figure_t &figure, const scale_options_t &options);
err_t figure_rotate(figure_t &figure, const rotate_options_t &options);

#endif // FIGURE_H
