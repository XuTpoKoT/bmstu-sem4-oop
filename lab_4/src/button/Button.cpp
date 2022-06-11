#include "Button.hpp"
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(press()));
    QObject::connect(this, SIGNAL(unpressSignal()), this, SLOT(unpress())); // Выключается когда лифт приедет и издаст сигнал

    state = INACTIVE;
    floor = 1;
}

void Button::setFloor(int floor)
{
    this->floor = floor;
}

void Button::press()
{
    // Если кнопка уже нажата, выходим
    if (this->state != INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet("background-color:pink");
    this->update();

    qDebug() << "[!] Вызов на этаж №" << this->floor;

    // Изменение состояния
    this->state = ACTIVE;
    this->setDisabled(true);

    // Сигнал всем, что нажата данная кнопка
    emit pressSignal(this->floor);
}

void Button::unpress()
{
    // Если кнопка уже разжата, выходим
    if (this->state == INACTIVE) return;

    // Визуальное изменение кнопки
    this->setStyleSheet("background-color:white");
    this->update();

    // Изменение состояния
    this->state = INACTIVE;
    this->setDisabled(false);
}
