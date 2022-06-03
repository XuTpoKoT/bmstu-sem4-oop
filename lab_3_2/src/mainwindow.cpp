#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    auto config = ProjectConfigCreator().createConfiguration();
    config->readConfiguration(CONFIG_SOURCE);
    facade = FacadeCreator().createFacade(config);
    ui->setupUi(this);
    setupDrawer();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupDrawer() {
    auto scene = std::make_shared<QGraphicsScene>(this);
    this->scene = scene;
    ui->graphicsView->setScene(scene.get());
    auto drawer = QtDrawerCreator(scene).createDrawer();
    this->drawer = drawer;

    SetupDrawerCommand command(DrawManager::setDrawer, drawer);
    facade->runCommand(command, DRAW_MANAGER);
}

void MainWindow::render() {
    DrawCommand command(DrawManager::drawScene, drawer);
    facade->runCommand(command, DRAW_MANAGER);
}

void MainWindow::on_loadModelButton_clicked() {
    try {
        std::string sourceName = QFileDialog::getOpenFileName(
            this,
            QString::fromUtf8("Открыть файл"),
            QDir::currentPath(),
            "text files (*.txt)"
            ).toLocal8Bit().constData();

        auto id = std::make_shared<int>(-1);

        AddModelCommand command(id, ModelLoadManager::loadModel, sourceName, 0);
        facade->runCommand(command, MODEL_LOAD_MANAGER);

        std::string modelName = std::string("MODEL_") + std::to_string(_modelIds.size());
        ui->comboBoxModel->addItem(modelName.c_str());
        _modelIds.push_back(*id);
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_addCameraButton_clicked() {
    try {
        auto id = std::make_shared<int>(-1);

        AddCameraCommand command(id, CameraAddManager::createCamera, 0);
        facade->runCommand(command, CAMERA_ADD_MANAGER);

        std::string cameraName = std::string("CAMERA_") + std::to_string(cameraIds.size());
        ui->comboBoxCamera->addItem(cameraName.c_str());

        cameraIds.push_back(*id);

    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_moveCameraButton_clicked() {
    try {
        auto currentCameraIndex = cameraIds.at(ui->comboBoxCamera->currentIndex());
        double x = ui->cameraInputDx->value();
        double y = ui->cameraInputDy->value();
        double z = ui->cameraInputDz->value();

        auto id = std::make_shared<int>(currentCameraIndex);

        MoveParams move = {x, y, z};
        MoveCameraCommand command(id, TransformManager::moveObject, move);
        facade->runCommand(command, TRANSFORM_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_rotateCameraButton_clicked() {
    try {
        auto currentCameraIndex = cameraIds.at(ui->comboBoxCamera->currentIndex());
        double x = ui->cameraInputOx->value();
        double y = ui->cameraInputOy->value();
        double z = ui->cameraInputOz->value();

        auto id = std::make_shared<int>(currentCameraIndex);
        RotateParams rotate = {x, y, z};
        RotateCameraCommand command(id, TransformManager::rotateObject, rotate);
        facade->runCommand(command, TRANSFORM_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_moveModelButton_clicked() {
    try {
        auto currentModelIndex = _modelIds.at(ui->comboBoxModel->currentIndex());
        double x = ui->modelInputDx->value();
        double y = ui->modelInputDy->value();
        double z = ui->modelInputDz->value();

        auto id = std::make_shared<int>(currentModelIndex);
        MoveParams move = {x, y, z};
        MoveModelCommand command(id, TransformManager::moveObject, move);
        facade->runCommand(command, TRANSFORM_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_scaleModelButton_clicked() {
    try {
        auto currentModelIndex = _modelIds.at(ui->comboBoxModel->currentIndex());
        double x = ui->modelInputKx->value();
        double y = ui->modelInputKy->value();
        double z = ui->modelInputKz->value();

        auto id = std::make_shared<int>(currentModelIndex);
        ScaleParams scale = {x, y, z};
        ScaleModelCommand command(id, TransformManager::scaleObject, scale);
        facade->runCommand(command, TRANSFORM_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_rotateModelButton_clicked() {
    try {
        auto currentModelIndex = _modelIds.at(ui->comboBoxModel->currentIndex());
        double x = ui->modelInputOx->value();
        double y = ui->modelInputOy->value();
        double z = ui->modelInputOz->value();

        auto id = std::make_shared<int>(currentModelIndex);
        RotateParams rotate = {x, y, z};
        RotateModelCommand command(id, TransformManager::rotateObject, rotate);
        facade->runCommand(command, TRANSFORM_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_removeCameraButton_clicked() {
    try {
        int comboBoxIndex = ui->comboBoxCamera->currentIndex();
        int cameraIndex = cameraIds.at(comboBoxIndex);

        auto id = std::make_shared<int>(cameraIndex);
        RemoveCameraCommand command(id, SceneManager::removeObject);
        facade->runCommand(command, SCENE_MANAGER);

        ui->comboBoxCamera->removeItem(comboBoxIndex);
        cameraIds.erase(cameraIds.begin() + comboBoxIndex);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_removeModelButton_clicked() {
    try {
        int comboBoxIndex = ui->comboBoxModel->currentIndex();
        int modelIndex = _modelIds.at(comboBoxIndex);

        auto id = std::make_shared<int>(modelIndex);
        RemoveModelCommand command(id, SceneManager::removeObject);
        facade->runCommand(command, SCENE_MANAGER);

        ui->comboBoxModel->removeItem(comboBoxIndex);
        _modelIds.erase(_modelIds.begin() + comboBoxIndex);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_setModelButton_clicked() {
    try {
        int comboBoxIndex = ui->comboBoxModel->currentIndex();
        int modelIndex = _modelIds.at(comboBoxIndex);

        auto id = std::make_shared<int>(modelIndex);
        SetCurrentModelCommand command(id, DrawManager::setCurrentModel);
        facade->runCommand(command, DRAW_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_setCameraButton_clicked() {
    try {
        int comboBoxIndex = ui->comboBoxCamera->currentIndex();
        int cameraIndex = cameraIds.at(comboBoxIndex);

        auto id = std::make_shared<int>(cameraIndex);
        SetCurrentCameraCommand command(id, DrawManager::setCurrentCamera);
        facade->runCommand(command, DRAW_MANAGER);

        render();
    } catch (BaseError &ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}
