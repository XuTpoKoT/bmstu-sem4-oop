#ifndef POINTS_H
#define POINTS_H

#include <cstdio>
#include <cstdlib>

#include "point.h"
#include "err.h"

struct points_t
{
    size_t count = 0;
    point_t *data = NULL;
};

void points_init(points_t &points);
err_t points_malloc(points_t &points, const size_t count);
void points_free(points_t &points);
err_t points_read(points_t &points, FILE *f);
point_t points_get(const points_t &points, size_t index);
// err_t points_create_copy(points_t &dst, const points_t &src);

void points_move(points_t &points, point_t &center, const move_options_t &options);
void points_scale(points_t &points, const point_t &center, const scale_options_t &options);
err_t points_rotate(points_t &points, const point_t &center, const rotate_options_t &options);

#endif // POINTS_H