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
        rc = MALLOC_POINTS_ERR;

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
    for (size_t i = 0; rc == OK && i < points.count; i++)
        rc = point_read(points.data[i], f);

    return rc;
}

static err_t read_points_count(size_t &count, FILE *f) {
    err_t rc = OK;
    if (fscanf(f, "%zu", &count) != 1 || count == 0)
        rc = READ_POINTS_COUNT_ERR;
    return rc;
}

err_t points_create(points_t &points, FILE *f) {
    size_t count;
    err_t rc = read_points_count(count, f);

    if (rc == OK) {
        rc = points_malloc(points, count);
        if (rc == OK) {
            rc = points_read(points, f);
            if (rc == READ_POINT_ERR)
                points_free(points);
        }
    }

    if (rc != OK)
        rc =  CREATE_POINTS_ERR;
    return rc;
}

point_t points_get(const points_t &points, size_t index) {
    return points.data[index];
}

bool points_are_correct(const points_t &points) {
    return points.count != 0;
}

err_t points_move(points_t &points, point_t &center, const move_options_t &options) {
    err_t rc = OK;
    if (points.count == 0)
        rc = FIGURE_WAS_NOT_INIT_ERR;

    if (rc == OK) {
        for (size_t i = 0; i < points.count; i++)
            point_move(points.data[i], options);
        point_move(center, options);
    }

    return rc;
}

err_t points_scale(points_t &points, const point_t &center, const scale_options_t &options) {
    err_t rc = OK;
    if (points.count == 0)
        rc = FIGURE_WAS_NOT_INIT_ERR;

    if (rc == OK)
        for (size_t i = 0; i < points.count; i++)
            point_scale(points.data[i], center, options);

    return rc;
}

err_t points_rotate(points_t &points, const point_t &center, const rotate_options_t &options) {
    err_t rc = OK;
    if (points.count == 0)
        rc = FIGURE_WAS_NOT_INIT_ERR;

    if (rc == OK)
        for (size_t i = 0; i < points.count && rc == OK; i++)
            rc = point_rotate(points.data[i], center, options);

    return rc;
}


