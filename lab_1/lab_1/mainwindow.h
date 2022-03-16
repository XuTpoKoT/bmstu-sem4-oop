#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define WINDOW_X 500
#define WINDOW_Y 500

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Move_clicked();

    void on_pushButton_Scale_clicked();

    void on_pushButton_Rotate_clicked();

    void on_pushButton_load_figure_clicked();

private:
    Ui::MainWindow *ui;
};

err_t execute_and_show(request_t req, Ui::MainWindow *ui);

#endif // MAINWINDOW_H
