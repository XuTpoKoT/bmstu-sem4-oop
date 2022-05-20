#include "vertice.h"
#include <cmath>
#include <iostream>

inline double to_radians(const double& angle)
{
    return angle * (M_PI / 180);
}

Vertice::Vertice(const double x, const double y, const double z)
    : _x(x)
    , _y(y)
    , _z(z)
{
}

Vertice::Vertice(const Vertice&& vertice) noexcept
    : _x(vertice._x)
    , _y(vertice._y)
    , _z(vertice._z)
{
    vertice.~Vertice();
}

Vertice& Vertice::operator=(Vertice&& vertice) noexcept
{
    set_x(vertice._x);
    set_y(vertice._y);
    set_z(vertice._z);
    vertice.~Vertice();

    return *this;
}

double Vertice::get_x() const
{
    return _x;
}

double Vertice::get_y() const
{
    return _y;
}

double Vertice::get_z() const
{
    return _z;
}

void Vertice::set_x(double const& x)
{
    _x = x;
}

void Vertice::set_y(double const& y)
{
    _y = y;
}

void Vertice::set_z(double const& z)
{
    _z = z;
}

Vertice Vertice::operator+(const Vertice& vertice)
{
    Vertice new_vertice { *this };

    new_vertice.set_x(new_vertice._x + vertice._x);
    new_vertice.set_y(new_vertice._y + vertice._y);
    new_vertice.set_z(new_vertice._z + vertice._z);

    return new_vertice;
}

Vertice Vertice::add(const Vertice& vertice)
{
    return *this + vertice;
}

Vertice Vertice::operator-(const Vertice& vertice)
{
    Vertice new_vertice { *this };

    new_vertice.set_x(new_vertice._x - vertice._x);
    new_vertice.set_y(new_vertice._y - vertice._y);
    new_vertice.set_z(new_vertice._z - vertice._z);

    return new_vertice;
}

Vertice Vertice::sub(const Vertice& vertice)
{
    return *this - vertice;
}

void Vertice::move(const double dx, const double dy, const double dz)
{
    set_x(_x + dx);
    set_y(_y + dy);
    set_z(_z + dz);
}

void Vertice::scale(const double kx, const double ky, const double kz)
{
    set_x(_x * kx);
    set_y(_y * ky);
    set_z(_z * kz);
}

void Vertice::rotate(const double ox, const double oy, const double oz)
{
    rotate_x(ox);
    rotate_y(oy);
    rotate_z(oz);
}

void Vertice::rotate_x(const double& ox)
{
    const double r_cos = cos(to_radians(ox));
    const double r_sin = sin(to_radians(ox));
    const double temp_y = _y;

    set_y(_y * r_cos + _z * r_sin);
    set_z(-temp_y * r_sin + _z * r_cos);
}

void Vertice::rotate_y(const double& oy)
{
    const double r_cos = cos(to_radians(oy));
    const double r_sin = sin(to_radians(oy));
    const double temp_x = _x;

    set_x(_x * r_cos + _z * r_sin);
    set_z(-temp_x * r_sin + _z * r_cos);
}

void Vertice::rotate_z(const double& oz)
{
    const double r_cos = cos(to_radians(oz));
    const double r_sin = sin(to_radians(oz));
    const double temp_x = _x;

    set_x(_x * r_cos + _y * r_sin);
    set_y(-temp_x * r_sin + _y * r_cos);
}

bool Vertice::operator==(const Vertice& vertice) const noexcept
{
    return (vertice._x == _x) && (vertice._y == _y) && (vertice._z == _z);
}

bool Vertice::operator!=(const Vertice& vertice) const noexcept
{
    return !(*this == vertice);
}
