#define _USE_MATH_DEFINES
#include "Sphere.h"
#include <stdexcept>

using namespace std;

Sphere::Sphere(const Point& center, const double radius) : center(center), radius(radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Ошибка: радиус шара должен быть положительным.");
    }
}

Sphere::Sphere(const Sphere& other)
{
    center = other.center;
    radius = other.radius;
}

Sphere::Sphere(Sphere&& other)
{
    center = other.center;
    radius = other.radius;

    other.radius = 1;
}

Sphere& Sphere::operator=(const Sphere& other)
{
    if (this == &other)
    {
        return *this;
    }

    center = other.center;
    radius = other.radius;

    return *this;
}

Sphere& Sphere::operator=(Sphere&& other)
{
    if (this == &other)
    {
        return *this;
    }

    center = other.center;
    radius = other.radius;

    other.radius = 1;

    return *this;
}

Point Sphere::GetCenter() const
{
    return center;
}

double Sphere::GetRadius() const
{
    return radius;
}

double Sphere::SurfaceArea() const
{
    return 4.0 * M_PI * radius * radius;
}

double Sphere::Volume() const
{
    return (4.0 / 3.0) * M_PI * pow(radius,3);
}

string Sphere::ToString() const
{
    return "Sphere(center=(" +
        to_string(center.GetX()) + ", " +
        to_string(center.GetY()) + ", " +
        to_string(center.GetZ()) + "), radius=" +
        to_string(radius) + ")";
}

Sphere Sphere::Read(istream& in)
{
    Point center;
    double radius;

    in >> center >> radius;

    if (!in)
    {
        throw runtime_error("Ошибка чтения шара из потока.");
    }

    return Sphere(center, radius);
}

ostream& operator<<(ostream& os, const Sphere& sphere)
{
    os << sphere.ToString();
    return os;
}
