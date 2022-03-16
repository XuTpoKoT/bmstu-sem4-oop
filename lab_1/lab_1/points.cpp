#include "points.h"

void points_init(points_t &points) {
    for (size_t i = 0; i < points.count; i++) {
        point_init(points.data[i]);
    }
}

err_t points_malloc(points_t &points, const size_t count)
{
    points.count = count;

    points.data = (point_t*)malloc(sizeof(point_t) * count);
    err_t rc = OK;
    if (points.data == NULL)
        rc = MEMORY_ERR;

    return rc;
}

void points_free(points_t &points)
{
    points.count = 0;
    free(points.data);
}

err_t points_read(points_t &points, FILE *f)
{
    err_t rc = OK;
    for (size_t i = 0; i < points.count && rc == OK; i++)
        rc = point_read(points.data[i], f);

    return rc;
}

point_t points_get(const points_t &points, size_t index) {
    return points.data[index];
}

void points_move(points_t &points, point_t &center, const move_options_t &options) {
    for (size_t i = 0; i < points.count; i++)
        point_move(points.data[i], options);
    point_move(center, options);
}

void points_scale(points_t &points, const point_t &center, const scale_options_t &options) {
    for (size_t i = 0; i < points.count; i++)
        point_scale(points.data[i], center, options);
}

err_t points_rotate(points_t &points, const point_t &center, const rotate_options_t &options) {
    err_t rc = OK;
    for (size_t i = 0; i < points.count && rc == OK; i++)
        rc = point_rotate(points.data[i], center, options);

    return rc;
}


