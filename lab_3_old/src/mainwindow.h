#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include "errors.h"
#include "facade_creator.h"
#include "project_config_creator.h"
#include "qt_drawer_creator.h"

#ifndef CONFIG_SOURCE
#define CONFIG_SOURCE "../lab_03/assets/config.txt"
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_moveCameraButton_clicked();
    void render();
    void on_loadModelButton_clicked();
    void on_moveModelButton_clicked();
    void on_addCameraButton_clicked();
    void on_rotateCameraButton_clicked();
    void on_scaleModelButton_clicked();
    void on_rotateModelButton_clicked();
    void on_setCameraButton_clicked();
    void on_removeCameraButton_clicked();
    void on_removeModelButton_clicked();
    void on_setModelButton_clicked();

private:
    std::shared_ptr<AbstractDrawerCreator> createQtDrawerFactory();
    void setupDrawer();
    Ui::MainWindow *ui;
    std::shared_ptr<Facade> facade;
    int _cameraCount;
    int _modelCount;
    std::shared_ptr<QGraphicsScene> scene;
    std::vector<int> _modelIds;
    std::vector<int> cameraIds;
    std::shared_ptr<AbstractDrawer> drawer;
};
#endif // MAINWINDOW_H
