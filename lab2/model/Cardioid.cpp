#include <iostream>
#include "Cardioid.h"

Cardioid::Cardioid(double a) : a(a) {}

double Cardioid::getA() const {
    return a;
}

void Cardioid::setA(double a) {
    this->a = a;
}

void Cardioid::printFormula() const {
    std::cout << "Cardioid: r(φ) = 2 * " << a << " * (1 - cos(φ))" << std::endl;
}

double Cardioid::getRadius(double angel) const {
    return 2 * a * (1 - cos(angel));
}

double Cardioid::getMaxRadius() const {
    return getRadius(M_PI);
}

double Cardioid::getRadiusPI() const noexcept {
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
    return 16 * a * angel / M_PI;
}
