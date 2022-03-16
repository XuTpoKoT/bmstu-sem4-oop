#ifndef ERR_H
#define ERR_H

#include <QMessageBox>

typedef enum
{
    OK,
    FILE_OPEN_ERR,
    FILE_CLOSE_ERR,
    FILE_FORMAT_ERR,
    MEMORY_ERR,
    READ_POINT_ERR,
    READ_LINK_ERR,
    UNKNOWN_COMMAND_ERR,
    NO_AXIS_ERR
} err_t;

void message_error(const err_t &error);

#endif // ERR_H
