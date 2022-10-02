#pragma once

#include <cmath>

class Cardioid {
private:
    double a;
public:

    Cardioid();
    Cardioid(double a);

    void setA(double a);

    double getA() const;

    const std::string getFormula() const;

    double getRadius(double angel) const;

    double getMaxRadius() const;

    double getRadiusPI() const;

    double getRadiusPI_2() const;

    double getRadiusPI_4() const;

    double getArea() const;

    double getLength(double angel) const;

};