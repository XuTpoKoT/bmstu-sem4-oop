#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "abstract_drawer.h"
#include "base_command.h"
#include "camera_command.h"
#include "errors.h"
#include "facade.h"
#include "model_command.h"
#include "scene_command.h"
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void setup_scene();

    void update_scene();

    void clear_scene();

    void check_cam_exist();

    void check_can_delete_cam();

    void check_models_exist();

private slots:
    void exit_messagebox();

    void change_cam();

    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

    void on_load_button_clicked();

    void on_delete_model_button_clicked();

    void on_add_camera_clicked();

    void on_delete_camera_clicked();

    void on_right_button_clicked();

    void on_up_button_clicked();

    void on_down_button_clicked();

    void on_left_button_clicked();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MainWindow* ui;
    QGraphicsScene* _scene;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<AbstractDrawer> _drawer;
    std::vector<size_t> _models;
    std::vector<size_t> _cameras;
    size_t _cam_id;
};
#endif // MAINWINDOW_H
