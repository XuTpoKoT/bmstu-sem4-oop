#ifndef ERR_H
#define ERR_H

#include <QMessageBox>

typedef enum
{
    OK,
    FILE_OPEN_ERR,
    FILE_CLOSE_ERR,
    FILE_FORMAT_ERR,
    FIGURE_WAS_NOT_INIT_ERR,
    // MEMORY_ERR,
    READ_POINT_ERR,
    MALLOC_POINTS_ERR,
    CREATE_POINTS_ERR,
    READ_POINTS_COUNT_ERR,
    READ_LINK_ERR,
    MALLOC_LINKS_ERR,
    CREATE_LINKS_ERR,
    READ_LINKS_COUNT_ERR,
    UNKNOWN_COMMAND_ERR,
    NO_AXIS_ERR
} err_t;

void message_error(const err_t &error);

#endif // ERR_H
