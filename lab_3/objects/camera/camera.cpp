#include "camera.h"

Camera::Camera()
    : _current_pos(0, 0, 0)
{
}

void Camera::move_x(const double& shift)
{
    _current_pos.set_x(_current_pos.get_x() + shift);
}

void Camera::move_y(const double& shift)
{
    _current_pos.set_y(_current_pos.get_y() + shift);
}

void Camera::move_z(const double& shift)
{
    _current_pos.set_z(_current_pos.get_z() + shift);
}

void Camera::transform(const Vertice& move, const Vertice& scale, const Vertice& rotate)
{
    move_x(move.get_x());
    move_y(move.get_y());
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

Vertice Camera::get_center() const
{
    return _current_pos;
}
