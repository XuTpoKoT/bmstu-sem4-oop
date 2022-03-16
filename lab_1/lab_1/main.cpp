#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

    return 0;
}
