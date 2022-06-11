#include "Controller.hpp"

#include <QLabel>
#include <QDebug>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    this->layout = std::make_unique<QVBoxLayout>();
    this->setLayout(this->layout.get());

    auto new_button = std::make_shared<Button>();
    new_button->setDisabled(true);
    new_button->setStyleSheet("background-color:darkgray; color:white");
    new_button->setFloor(FLOORS + 1);
    new_button->setText("Floor Buttons");

    this->floorButtons.insert(this->floorButtons.begin(), new_button);
    layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

    for (size_t i = 0; i < FLOORS; i++)
    {
        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));

        this->floorButtons.insert(this->floorButtons.begin(), new_button);
        layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        floorsToVisit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(new_button.get(), SIGNAL(pressSignal(int)), this, SLOT(addTarget(int)));
    }

    auto lift_button = std::make_shared<Button>();
    lift_button->setDisabled(true);
    lift_button->setStyleSheet("background-color:darkgray; color:white");
    lift_button->setFloor(2 * FLOORS + 2);
    lift_button->setText("Lift Buttons");
    this->liftButtons.insert(this->liftButtons.begin(), lift_button);
    layout->addWidget(dynamic_cast<QPushButton *>(lift_button.get()));


    for (size_t i = 0; i < FLOORS; i++)
    {
        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));

        this->liftButtons.insert(this->liftButtons.begin(), new_button);
        layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        floorsToVisit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(new_button.get(), SIGNAL(pressSignal(int)), this, SLOT(addTarget(int)));
    }

    QObject::connect(this, SIGNAL(reachFloorSignal()), this, SLOT(reachFloor()));
}

void Controller::addTarget(int floor)
{
    floorsToVisit[floor - 1] = true;
    newTarget();
}

void Controller::newTarget()
{
    state = BUSY;
    if (defineNewTarget()) {
        if (curFloor == targetFloor)
            emit reachFloorSignal();
        else {
            updateFloor();
            emit moveCabinSignal();
        }
     }
}

bool Controller::defineNewTarget()
{
    Direction dir;
    dir = direction;

    for (int i = curFloor; i <= FLOORS && i > 0; i = i + dir)
        if (floorsToVisit[i - 1]) {
            targetFloor = i;
            return true;
        }

    dir = ((dir == UP) ? DOWN : UP);

    for (int i = curFloor; i <= FLOORS && i > 0; i = i + dir)
        if (floorsToVisit[i - 1]) {
            targetFloor = i;
            direction = dir;
            return true;
        }

    return false;
}

void Controller::reachFloor()
{
    // Если контроллер не занят, выходим [лифт не движется]
    if (state != BUSY) return;

    qDebug() << "[!] Лифт приехал на этаж № " << targetFloor;

    emit floorButtons[targetFloor - 1]->unpressSignal();
    emit liftButtons[targetFloor - 1]->unpressSignal();

    floorsToVisit[targetFloor - 1] = false;

    if (defineNewTarget())
        emit stopCabinSignal();
    else {
        state = FREE;
        emit stopCabinSignal();
    }
}

void Controller::updateFloor()
{
    curFloor += direction;

     qDebug() << "... Лифт едет на этаж № " << curFloor;
}
