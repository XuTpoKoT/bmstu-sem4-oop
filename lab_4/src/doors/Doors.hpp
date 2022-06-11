#ifndef LAB_04_DOORS_HPP
#define LAB_04_DOORS_HPP

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT

    using DoorsState = enum {
        OPEN,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    Doors();
    ~Doors() override = default;

signals:
    void doorClosed();

public slots:
    void startOpening();  // -> OPENING

private slots:
    void startClosing();  // -> CLOSING
    void open();          // -> OPEN
    void close();         // -> CLOSED

private:
    DoorsState state;

    QTimer openTimer;
    QTimer closeTimer;
    QTimer waitTimer;
};

#endif//LAB_04_DOORS_HPP
