#ifndef POINT_H
#define POINT_H

#include <cstdio>

#include "err.h"

struct point_t
{
    double x;
    double y;
    double z;
};

struct move_options_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_options_t
{
    double kx;
    double ky;
    double kz;
};

enum axis_t {
    X,
    Y,
    Z,
    NO_AXIS
};

struct rotate_options_t
{
    axis_t axis;
    double angle;
};

void point_init(point_t &point);
err_t point_read(point_t &point, FILE *f);
void point_copy(point_t &dst, const point_t &src);

void point_move(point_t &point, const move_options_t &options);
void point_scale(point_t &point, const point_t &center, const scale_options_t &options);
err_t point_rotate(point_t &point, const point_t &center, const rotate_options_t &options);

#endif // POINT_H
