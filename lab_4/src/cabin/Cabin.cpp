#include "Cabin.hpp"
#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    state = FREE;

    // Сигнал открывания дверей => просим открыть двери
    QObject::connect(this, SIGNAL(openDoors()), &doors, SLOT(startOpening()));

    // Кабина закончила движение => она свободна, выдаём сигнал cabinFinished()
    QObject::connect(&moveTimer, SIGNAL(timeout()), this, SLOT(free()));

    // Двери закрылись => кабина освободилась, выдаём сигнал cabinFinished()
    QObject::connect(&doors, SIGNAL(doorClosed()), this, SLOT(free()));
}

void Cabin::stopCabin()
{
        state = WAITS;

        moveTimer.stop();
        emit openDoors(); // signal открыть двери
 }

void Cabin::moveCabin()
{
    if (state == FREE || state == MOVING) {
        state = MOVING;
        moveTimer.start(MOVE_TIME);
    }
}

void Cabin::free()
{
    if (state != FREE) {
        state = FREE;
        emit cabinFinished(false);
    }
}
