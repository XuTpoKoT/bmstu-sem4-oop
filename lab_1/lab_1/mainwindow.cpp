#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusbar->showMessage("Лабораторная работа №1, Морозов Дмитрий ИУ7-42Б");
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    request_t request;
    request.action = LOAD_FIGURE;
    request.filename = "../lab_1/figure_3.txt";
    request.scene = scene;
    execute_and_show(request, ui);
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = EXIT;
    execute(request);
    delete ui;
}

err_t execute_and_show(request_t req, Ui::MainWindow *ui)
{
    err_t rc = execute(req);
    if (rc == OK) {
        request_t draw_request = {
            .action = DRAW,
            .scene = ui->graphicsView->scene()
        };
        rc = execute(draw_request);
    }

    return rc;
}

void MainWindow::on_pushButton_Move_clicked()
{
    std::cout << "Move\n";
    request_t request;
    request.action = MOVE;

    move_options_t move_options;
    move_options.dx = ui->doubleSpinBox_moveX->value();
    move_options.dy = ui->doubleSpinBox_moveY->value();
    move_options.dz = ui->doubleSpinBox_moveZ->value();

    request.move_options = move_options;
    err_t rc = execute_and_show(request, ui);
    if (rc != OK)
        message_error(rc);
}

void MainWindow::on_pushButton_Scale_clicked()
{
    request_t request;
    request.action = SCALE;

    scale_options_t scale_options;
    scale_options.kx = ui->doubleSpinBox_scaleX->value();
    scale_options.ky = ui->doubleSpinBox_scaleY->value();
    scale_options.kz = ui->doubleSpinBox_scaleZ->value();

    request.scale_options = scale_options;
    err_t rc = execute_and_show(request, ui);
    if (rc != OK)
        message_error(rc);
}

void MainWindow::on_pushButton_Rotate_clicked()
{
    request_t request;
    request.action = ROTATE;

    rotate_options_t rotate_options;
    if (ui->radioButton_x->isChecked()) {
        rotate_options.axis = X;
    } else if (ui->radioButton_y->isChecked()) {
        rotate_options.axis = Y;
    } else if (ui->radioButton_z->isChecked()) {
        rotate_options.axis = Z;
    } else {
        rotate_options.axis = NO_AXIS;
    }

    rotate_options.angle = ui->doubleSpinBox_angle->value();
    request.rotate_options = rotate_options;
    err_t rc = execute_and_show(request, ui);
    if (rc != OK)
        message_error(rc);
}
