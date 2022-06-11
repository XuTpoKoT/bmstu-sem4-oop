#include "Doors.hpp"
#include "../defines.hpp"
#include <QDebug>

Doors::Doors() : state(CLOSED)
{
    QObject::connect(&openTimer, SIGNAL(timeout()), this, SLOT(open())); // timeout() - сигнал из qtimer
    QObject::connect(&waitTimer,  SIGNAL(timeout()), this, SLOT(startClosing()));
    QObject::connect(&closeTimer, SIGNAL(timeout()), this, SLOT(close()));
}

void Doors::startOpening()
{
    // Если двери не закрыты и не закрываются, то начать открывать её не можем
    if (state != CLOSED && state != CLOSING) return;

    state = OPENING;
    qDebug() << "Двери открываются...";

    auto timer = closeTimer.remainingTime();
    closeTimer.stop();
    openTimer.start(DOOR_TIME - timer);
}

void Doors::open()
{
    if (state != OPENING) return;

    state = OPEN;

    qDebug() << "[*] Двери открыты!";

    waitTimer.start(WAIT_TIME);
}

void Doors::close()
{
    if (state != CLOSING) return;

    state = CLOSED;

    qDebug() << "[*] Двери закрылись!";

    emit doorClosed();
}

void Doors::startClosing()
{
    if (state != OPEN) return;

    state = CLOSING;

    qDebug() << "Двери закрываются...";

    closeTimer.start(DOOR_TIME);
}
