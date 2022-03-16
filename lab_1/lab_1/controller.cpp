#include "controller.h"

err_t execute(request_t &req)
{
    err_t rc = OK;
    static figure_t figure = figure_init();

    switch (req.action)
    {
        case LOAD_FIGURE:
            rc = figure_load(figure, req.filename);
            break;
        case DRAW:
            draw_figure(req.scene, figure);
            break;
        case MOVE:
            figure_move(figure, req.move_options);
            break;
        case SCALE:
            figure_scale(figure, req.scale_options);
            break;
        case ROTATE:
            rc = figure_rotate(figure, req.rotate_options);
            break;
        case EXIT:
            figure_free(figure);
            break;
        default:
            rc = UNKNOWN_COMMAND_ERR;
    }

    return rc;
}
