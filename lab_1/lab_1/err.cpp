#include "err.h"

void message_error(const err_t &error)
{
    switch (error)
    {
        case FILE_OPEN_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Ошибка открытия файла.");
            break;
        case FILE_CLOSE_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                              "Ошибка закрытия файла.");
        break;
        case FILE_FORMAT_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Неверный формат файла.");
            break;
        case MALLOC_POINTS_ERR:
        case MALLOC_LINKS_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Не удалось выделить память.");
            break;
        case READ_POINT_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Ошибка чтения точки.");
            break;
        case READ_LINK_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Ошибка чтения связи.");
            break;
        case NO_AXIS_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                              "Не выбрана ось вращения.");
            break;
        case UNKNOWN_COMMAND_ERR:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Неизвестная команда.");
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка!",
                                  "Неизвестная ошибка.");
    }
}
