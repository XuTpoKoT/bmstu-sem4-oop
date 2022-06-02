#pragma once

#include <istream>
#include <memory>
#include <math.h>

#include "vector.h"

class Point {
public:
    Point() = default;
    Point(double x, double y, double z);

    Point(const Point& Point) = default;
    Point(const Point&& Point) noexcept;

    Point& operator=(const Point& Point) = default;
    Point& operator=(Point&& Point) noexcept;

    bool operator==(const Point& Point) const noexcept;
    bool operator!=(const Point& Point) const noexcept;

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void move(double dx, double dy, double dz);
    void scale(double kx, double ky, double kz);
    void rotate(double ox, double oy, double oz);

    void rotateX(double ox);
    void rotateY(double oy);
    void rotateZ(double oz);

private:
    double x, y, z;
};
