#ifndef CAMERA_H
#define CAMERA_H

#include "draw_visitor.h"
#include "object.h"

class Camera : public InvisibleObject {
public:
    friend class DrawVisitor;

    Camera();
    explicit Camera(const Vertice& pos)
        : _current_pos(pos) {};
    ~Camera() override = default;

    void transform(const Vertice& move, const Vertice& scale, const Vertice& rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    virtual Vertice get_center() const override;

private:
    void move_x(const double& shift);
    void move_y(const double& shift);
    void move_z(const double& shift);

    Vertice _current_pos;
};

#endif // CAMERA_H
