#ifndef LAB_04_BUTTON_HPP
#define LAB_04_BUTTON_HPP

#include <QPushButton>
#include <memory>

class Button : public QPushButton
{
    Q_OBJECT;

    using buttonState = enum {
        ACTIVE,
        INACTIVE
    };

public:
    explicit Button(QWidget *parent = nullptr);
    ~Button() override = default;

    void setFloor(int floor);

signals:
    void pressSignal(int);
    void unpressSignal();

public slots:
    void press();
    void unpress();

private:
    buttonState state;
    size_t floor;
};

#endif// LAB_04_BUTTON_HPP
