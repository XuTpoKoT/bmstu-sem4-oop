#include "mainwindow.h"
#include "drawer_factory_solution.h"
#include "qt_drawer_factory.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_scene();
    _facade = std::make_shared<Facade>(Facade());

    connect(ui->load_button, SIGNAL(triggered()), this, SLOT(on_load_button_clicked()));
    connect(ui->delete_model, &QPushButton::clicked, this, &MainWindow::on_delete_model_button_clicked);

    connect(ui->add_camera, &QPushButton::clicked, this, &MainWindow::on_add_camera_clicked);
    connect(ui->delete_camera, &QPushButton::clicked, this, &MainWindow::on_delete_camera_clicked);

    connect(ui->clear_screen, &QPushButton::clicked, this, &MainWindow::clear_scene);

    connect(ui->right_button, &QPushButton::clicked, this, &MainWindow::on_right_button_clicked);
    connect(ui->up_button, &QPushButton::clicked, this, &MainWindow::on_up_button_clicked);
    connect(ui->down_button, &QPushButton::clicked, this, &MainWindow::on_down_button_clicked);
    connect(ui->left_button, &QPushButton::clicked, this, &MainWindow::on_left_button_clicked);

    connect(ui->move_button, &QPushButton::clicked, this, &MainWindow::on_move_button_clicked);
    connect(ui->scale_button, &QPushButton::clicked, this, &MainWindow::on_scale_button_clicked);
    connect(ui->turn_button, &QPushButton::clicked, this, &MainWindow::on_turn_button_clicked);

    connect(ui->camera_choose, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::change_cam);

    connect(ui->exit, SIGNAL(triggered()), this, SLOT(exit_messagebox()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit_messagebox()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Выход", "Вы уверены, что хотите выйти?",
        QMessageBox::Ok | QMessageBox::Cancel);
    if (reply == QMessageBox::Ok) {
        QApplication::quit();
    }
}

void MainWindow::check_cam_exist()
{
    if (_cameras.size() == 0) {
        std::string message = "No camera found.";
        throw CameraError(message);
    }
}

void MainWindow::check_can_delete_cam()
{
    if (_cameras.size() <= 1 && _models.size()) {
        std::string message = "Can not delete the last camera with the loaded models";
        throw CameraError(message);
    }
}

void MainWindow::check_models_exist()
{
    if (_models.size() == 0) {
        std::string message = "No models found.";
        throw ModelError(message);
    }
}

void MainWindow::on_move_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    MoveModel move_command(
        ui->dx_box->value(),
        ui->dy_box->value(),
        ui->dz_box->value(),
        _models.at(ui->model_choose->currentIndex()));
    _facade->execute(move_command);
    update_scene();
}

void MainWindow::on_scale_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    ScaleModel scale_command(
        ui->kx_box->value(),
        ui->ky_box->value(),
        ui->kz_box->value(),
        _models.at(ui->model_choose->currentIndex()));
    _facade->execute(scale_command);
    update_scene();
}

void MainWindow::on_turn_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    RotateModel rotate_command(
        ui->ox_box->value(),
        ui->oy_box->value(),
        ui->oz_box->value(),
        _models.at(ui->model_choose->currentIndex()));
    _facade->execute(rotate_command);
    update_scene();
}

void MainWindow::on_load_button_clicked()
{
    try {
        check_cam_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем добавлять модель, добавьте хотя бы одну камеру.");
        return;
    }

    QString fname_tmp1 = QFileDialog::getOpenFileName();

    if (fname_tmp1.isNull())
        return;

    QByteArray fname_tmp2 = fname_tmp1.toUtf8();
    std::string fname = fname_tmp2.data();

    auto id = std::make_shared<size_t>(0);
    LoadModel load_command(id, fname);

    try {
        _facade->execute(load_command);
    } catch (const LoadError& error) {
        std::cout << error.what();
        QMessageBox::critical(nullptr, "Ошибка", "Что-то пошло не так при загрузке файла...");
        return;
    }

    _models.push_back(*id);
    update_scene();
    ui->model_choose->addItem(QFileInfo(fname_tmp1.toUtf8().data()).fileName());
    ui->model_choose->setCurrentIndex(ui->model_choose->count() - 1);
}

void MainWindow::on_delete_model_button_clicked()
{
    try {
        check_models_exist();
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
        return;
    }

    size_t id = _models.at(ui->model_choose->currentIndex());
    RemoveModel remove_command(id);
    _facade->execute(remove_command);

    _models.erase(_models.begin() + ui->model_choose->currentIndex());
    ui->model_choose->removeItem(ui->model_choose->currentIndex());

    update_scene();
}

void MainWindow::setup_scene()
{
    _scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto rcontent = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());

    std::shared_ptr<AbstractDrawerFactory> factory = DrawerFactorySolution<QGraphicsScene>().create_factory(_scene);
    _drawer = factory->create_drawer();
}

void MainWindow::update_scene()
{
    DrawScene draw_command(_drawer);
    _facade->execute(draw_command);
}

void MainWindow::clear_scene()
{
    try {
        check_models_exist();
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модели, добавьте хотя бы одну.");
        return;
    }

    for (int i = ui->model_choose->count() - 1; i >= 0; --i) {
        size_t id = _models.at(i);

        RemoveModel remove_command(id);
        _facade->execute(remove_command);

        _models.erase(_models.begin() + i);
        ui->model_choose->removeItem(i);
    }

    update_scene();
}

void MainWindow::on_add_camera_clicked()
{
    auto rcontent = ui->graphicsView->contentsRect();
    auto id = std::make_shared<size_t>(0);
    AddCamera camera_command(id, rcontent.width() / 2.0, rcontent.height() / 2.0, 0.0);
    _facade->execute(camera_command);
    _cameras.push_back(*id);

    update_scene();

    auto cam = ui->camera_choose;
    if (0 == cam->count())
        cam->addItem(QString::number(1));
    else
        cam->addItem(QString::number(
            cam->itemText(cam->count() - 1).toInt() + 1));

    ui->camera_choose->setCurrentIndex(ui->camera_choose->count() - 1);
}

void MainWindow::on_delete_camera_clicked()
{
    try {
        check_cam_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
        return;
    }

    try {
        check_can_delete_cam();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, необходимо удалить оставшиеся модели.");
        return;
    }

    size_t id = _cameras.at(ui->camera_choose->currentIndex());
    RemoveCamera remove_command(id);
    _facade->execute(remove_command);

    _cameras.erase(_cameras.begin() + ui->camera_choose->currentIndex());
    ui->camera_choose->removeItem(ui->camera_choose->currentIndex());

    try {
        check_cam_exist();
    } catch (const CameraError& error) {
        return;
    }

    update_scene();
}

void MainWindow::change_cam()
{
    try {
        check_cam_exist();
    } catch (const CameraError& error) {
        return;
    }

    size_t id = _cameras.at(ui->camera_choose->currentIndex());
    SetCamera camera_command(id);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_right_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    size_t id = _cameras.at(ui->camera_choose->currentIndex());
    MoveCamera camera_command(id, 10, 0);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_up_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    size_t id = _cameras.at(ui->camera_choose->currentIndex());
    MoveCamera camera_command(id, 0, -10);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_down_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }

    size_t id = _cameras.at(ui->camera_choose->currentIndex());
    MoveCamera camera_command(id, 0, 10);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_left_button_clicked()
{
    try {
        check_cam_exist();
        check_models_exist();
    } catch (const CameraError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    } catch (const ModelError& error) {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной модели");
        return;
    }
    size_t id = _cameras.at(ui->camera_choose->currentIndex());
    MoveCamera camera_command(id, -10, 0);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    _scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());

    auto rcontent = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());
}
