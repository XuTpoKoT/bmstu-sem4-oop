#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "drawer.h"
#include "figure.h"
#include "err.h"

enum action_t
{
    LOAD_FIGURE,
    DRAW,
    MOVE,
    SCALE,
    ROTATE,
    EXIT
};

struct request_t
{
    action_t action;
    const char *filename;
    drawer_t drawer;
    move_options_t move_options;
    scale_options_t scale_options;
    rotate_options_t rotate_options;
};

err_t execute(request_t &req);

#endif // CONTROLLER_H
