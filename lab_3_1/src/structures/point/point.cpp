#include "point.h"
#include <cmath>
#include <iostream>

double to_radians(double angle)
{
    return angle * (M_PI / 180);
}

Point::Point(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z)
{
}

Point::Point(const Point&& Point) noexcept
    : x(Point.x)
    , y(Point.y)
    , z(Point.z)
{
    Point.~Point();
}

Point& Point::operator=(Point&& Point) noexcept
{
    setX(Point.x);
    setY(Point.y);
    setZ(Point.z);
    Point.~Point();

    return *this;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

void Point::setZ(double z)
{
    this->z = z;
}

void Point::move(double dx, double dy, double dz)
{
    setX(x + dx);
    setY(y + dy);
    setZ(z + dz);
}

void Point::scale(double kx, double ky, double kz)
{
    setX(x * kx);
    setY(y * ky);
    setZ(z * kz);
}

void Point::rotate(double ox, double oy, double oz)
{
    rotateX(ox);
    rotateY(oy);
    rotateZ(oz);
}

void Point::rotateX(double ox)
{
    const double r_cos = cos(to_radians(ox));
    const double r_sin = sin(to_radians(ox));
    const double tempy = y;

    setY(y * r_cos + z * r_sin);
    setZ(-tempy * r_sin + z * r_cos);
}

void Point::rotateY(double oy)
{
    const double r_cos = cos(to_radians(oy));
    const double r_sin = sin(to_radians(oy));
    const double tempx = x;

    setX(x * r_cos + z * r_sin);
    setZ(-tempx * r_sin + z * r_cos);
}

void Point::rotateZ(double oz)
{
    const double r_cos = cos(to_radians(oz));
    const double r_sin = sin(to_radians(oz));
    const double tempx = x;

    setX(x * r_cos + y * r_sin);
    setY(-tempx * r_sin + y * r_cos);
}

bool Point::operator==(const Point& Point) const noexcept
{
    return (Point.x == x) && (Point.y == y) && (Point.z == z);
}

bool Point::operator!=(const Point& Point) const noexcept
{
    return !(*this == Point);
}
