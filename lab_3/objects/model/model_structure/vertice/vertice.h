#ifndef VERTICE_H
#define VERTICE_H

class Vertice {
public:
    Vertice() = default;
    Vertice(const double x, const double y, const double z);

    Vertice(const Vertice& vertice) = default;
    Vertice(const Vertice&& vertice) noexcept;

    Vertice& operator=(const Vertice& vertice) = default;
    Vertice& operator=(Vertice&& vertice) noexcept;

    bool operator==(const Vertice& vertice) const noexcept;
    bool operator!=(const Vertice& vertice) const noexcept;

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double const& x);
    void set_y(double const& y);
    void set_z(double const& z);

    Vertice operator+(const Vertice& vertice);
    Vertice add(const Vertice& vertice);

    Vertice operator-(const Vertice& vertice);
    Vertice sub(const Vertice& vertice);

    void move(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void rotate(const double ox, const double oy, const double oz);

    void rotate_x(const double& ox);
    void rotate_y(const double& oy);
    void rotate_z(const double& oz);

private:
    double _x, _y, _z;
};

#endif // VERTICE_H
