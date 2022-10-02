#include <iostream>
#include "Cardioid.h"

Cardioid::Cardioid(double a) : a(a) {}

double Cardioid::getA() const {
    return a;
}

void Cardioid::setA(double a) {
    this->a = a;
}

const std::string Cardioid::getFormula() const {
    std::string value = (a == int(a)) ? std::to_string(int(a)) : std::to_string(a);
    return "Cardioid: r(φ) = 2 * " + value + " * (1 - cos(φ))";
}

double Cardioid::getRadius(double angel) const {
    return 2 * a * (1 - cos(angel));
}

double Cardioid::getMaxRadius() const {
    return getRadius(M_PI);
}

double Cardioid::getRadiusPI() const {
    return getRadius(M_PI);
}

double Cardioid::getRadiusPI_2() const {
    return getRadius(M_PI_2);
}

double Cardioid::getRadiusPI_4() const {
    return getRadius(M_PI_4);
}

double Cardioid::getArea() const {
    return 6 * M_PI * a * a;
}

double Cardioid::getLength(double angel) const {
    return 16 * std::abs(a) * angel / M_PI;
}

Cardioid::Cardioid() : a(0) {}