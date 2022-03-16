#include <iostream>

#include "figure.h"

figure_t& figure_init() {
    static figure_t figure;
    points_init(figure.points);
    links_init(figure.links);
    return figure;
}

err_t figure_load(figure_t &figure, const char *filename)
{
    err_t rc = OK;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        rc = FILE_OPEN_ERR;

    if (rc == OK)
        rc = figure_read(figure, f);

    if (f != NULL && fclose(f) != 0)
        rc = FILE_CLOSE_ERR;

    return rc;
}

err_t figure_read(figure_t &figure, FILE *f) {
    err_t rc = OK;
    figure_t buf_figure;
    size_t points_cnt;

    if (fscanf(f, "%zu", &points_cnt) != 1 || points_cnt == 0)
        rc =  FILE_FORMAT_ERR;

    if (rc == OK)
        rc = points_malloc(buf_figure.points, points_cnt);

    if (rc == OK)
        rc = points_read(buf_figure.points, f);

    size_t links_cnt;
    if (rc == OK && (fscanf(f, "%zu", &links_cnt) != 1 || links_cnt == 0))
        rc =  FILE_FORMAT_ERR;

    if (rc == OK)
        rc = links_malloc(buf_figure.links, links_cnt);

    if (rc == OK)
        rc = links_read(buf_figure.links, f);

    if (rc == OK) {
        figure_free(figure);
        //    points_free(figure.points);
        //    links_free(figure.links);
        figure = buf_figure;
    }
    else
        figure_free(buf_figure);

    return rc;
}

void figure_free(figure_t &figure)
{
    points_free(figure.points);
    links_free(figure.links);
}

//err_t figure_create_copy(figure_t &dst, const figure_t &src)
//{
//    err_t rc = points_create_copy(dst.points, src.points);

//    if (rc == OK)
//        rc = links_create_copy(dst.links, src.links);

//    if (rc != OK)
//        figure_free(dst);

//    return rc;
//}

void figure_move(figure_t &figure, const move_options_t &options)
{
    points_move(figure.points, figure.center, options);
}

void figure_scale(figure_t &figure, const scale_options_t &options)
{
    points_scale(figure.points, figure.center, options);
}

err_t figure_rotate(figure_t &figure, const rotate_options_t &options)
{
    return points_rotate(figure.points, figure.center, options);
}


