#pragma once

#include <cmath>

class Cardioid {
private:
    double a;
public:
    Cardioid(double a);

    void setA(double a);

    double getA() const;

    void printFormula() const;

    double getRadius(double angel) const;

    double getMaxRadius() const;

    double getRadiusPI() const noexcept;

    double getRadiusPI_2() const;

    double getRadiusPI_4() const;

    double getArea() const;

    double getLength(double angel) const;

};