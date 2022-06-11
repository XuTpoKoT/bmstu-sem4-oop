#ifndef LAB_04_CONTROLLER_HPP
#define LAB_04_CONTROLLER_HPP

#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <memory>
#include <vector>

#include "src/defines.hpp"
#include "src/button/Button.hpp"

class Controller : public QWidget
{
    Q_OBJECT

    using ControllerState = enum {
        FREE,
        BUSY
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() override = default;

signals:
    void stopCabinSignal();
    void moveCabinSignal();
    void reachFloorSignal();

public slots:
    void newTarget();           // -> BUSY
    void addTarget(int);        // -> BUSY
    void reachFloor();          // -> FREE

private:
    bool defineNewTarget();
    void updateFloor();

private:
    int curFloor = 1;
    int targetFloor = 1;
    Direction direction = UP;

    ControllerState state = FREE;
    std::vector<bool> floorsToVisit;

    std::vector<std::shared_ptr<Button>> floorButtons;
    std::vector<std::shared_ptr<Button>> liftButtons;
    std::unique_ptr<QVBoxLayout> layout;
};

#endif//LAB_04_CONTROLLER_HPP
