#include <math.h>

#include "point.h"

void point_init(point_t &point) {
    point.x = 0;
    point.y = 0;
    point.z = 0;
}

void point_copy(point_t &dst, const point_t &src) {
    dst.x = src.x;
    dst.y = src.y;
    dst.z = src.z;
}

err_t point_read(point_t &point, FILE *f) {
    err_t rc = OK;
    if (fscanf(f, "%lf%lf%lf", &point.x, &point.y, &point.z) != 3)
        rc = READ_POINT_ERR;
    return rc;
}

void point_move(point_t &point, const move_options_t &options) {
    point.x += options.dx;
    point.y += options.dy;
    point.z += options.dz;
}

void point_scale(point_t &point, const point_t &center, const scale_options_t &options) {
    point.x = point.x * options.kx + (1 - options.kx) * center.x;
    point.y = point.y * options.ky + (1 - options.ky) * center.y;
    point.z = point.z * options.kz + (1 - options.kz) * center.z;
}

static void point_rotate_x(point_t &point, const point_t &center, const double &angle) {
    double angle_in_radians = angle / 180 * M_PI;
    double cos_val = cos(angle_in_radians);
    double sin_val = sin(angle_in_radians);
    double buf_y = point.y;

    point.y = center.y + (point.y - center.y) * cos_val + (point.z - center.z) * sin_val;
    point.z = center.z + (point.z - center.z) * cos_val - (buf_y - center.y) * sin_val;
}

static void point_rotate_y(point_t &point, const point_t &center, const double &angle) {
    double angle_in_radians = angle / 180 * M_PI;
    double cos_val = cos(angle_in_radians);
    double sin_val = sin(angle_in_radians);
    double buf_x = point.x;

    point.x = center.x + (point.x - center.x) * cos_val + (point.z - center.z) * sin_val;
    point.z = center.z + (point.z - center.z) * cos_val - (buf_x - center.x) * sin_val;
}

static void point_rotate_z(point_t &point, const point_t &center, const double &angle) {
    double angle_in_radians = angle / 180 * M_PI;
    double cos_val = cos(angle_in_radians);
    double sin_val = sin(angle_in_radians);
    double buf_x = point.x;

    point.x = center.x + (point.x - center.x) * cos_val + (point.y - center.y) * sin_val;
    point.y = center.y + (point.y - center.y) * cos_val - (buf_x - center.x) * sin_val;
}

err_t point_rotate(point_t &point, const point_t &center, const rotate_options_t &options) {
    err_t rc = OK;
    switch (options.axis) {
        case X:
            point_rotate_x(point, center, options.angle);
            break;
        case Y:
            point_rotate_y(point, center, options.angle);
            break;
        case Z:
            point_rotate_z(point, center, options.angle);
            break;
        default:
            rc = NO_AXIS_ERR;
    }

    return rc;
}

