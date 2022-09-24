#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "Cardioid.h"

TEST_CASE("is coefficient changeable", "[cardioid]") {
    Cardioid cardioid = Cardioid(10);
    REQUIRE(cardioid.getA() == 10);
    CHECK(cardioid.getFormula() == "Cardioid: r(φ) = 2 * 10 * (1 - cos(φ))");
    SECTION("set int coefficient") {
        cardioid.setA(20);
        CHECK(cardioid.getA() == 20);
    }SECTION("set double coefficient") {
        cardioid.setA(20.255690123);
        CHECK(cardioid.getA() == 20.255690123);
    }SECTION("set zero coefficient") {
        cardioid.setA(0);
        CHECK(cardioid.getA() == 0);
    }SECTION("set negative coefficient") {
        cardioid.setA(-0.123321);
        CHECK(cardioid.getA() == -0.123321);
    }
}

TEST_CASE("check radius", "[cardioid]") {
    Cardioid cardioid = Cardioid(10);
    REQUIRE(cardioid.getA() == 10);
    SECTION("check zero angel radius") {
        CHECK(cardioid.getRadius(0) == 0);
        cardioid.setA(20);
        CHECK(cardioid.getRadius(0) == 0);
        cardioid.setA(-20);
        CHECK(cardioid.getRadius(0) == 0);
        cardioid.setA(20.1231);
        CHECK(cardioid.getRadius(0) == 0);
        cardioid.setA(0);
        CHECK(cardioid.getRadius(0) == 0);
    }SECTION("check PI angel radius") {
        cardioid.setA(10);
        CHECK(cardioid.getRadius(M_PI) == Approx(40));
        CHECK(cardioid.getRadius(M_PI) == cardioid.getRadiusPI());
        cardioid.setA(20);
        CHECK(cardioid.getRadius(M_PI) == Approx(80));
        CHECK(cardioid.getRadius(M_PI) == cardioid.getRadiusPI());
        cardioid.setA(-20);
        CHECK(cardioid.getRadius(M_PI) == Approx(-80));
        CHECK(cardioid.getRadius(M_PI) == cardioid.getRadiusPI());
        cardioid.setA(0);
        CHECK(cardioid.getRadius(M_PI) == Approx(0));
        CHECK(cardioid.getRadius(M_PI) == cardioid.getRadiusPI());
        cardioid.setA(-10.05);
        CHECK(cardioid.getRadius(M_PI) == Approx(-40.2));
        CHECK(cardioid.getRadius(M_PI) == cardioid.getRadiusPI());
    }SECTION("check PI/2 angel radius") {
        cardioid.setA(10);
        CHECK(cardioid.getRadius(M_PI_2) == Approx(20));
        CHECK(cardioid.getRadius(M_PI_2) == cardioid.getRadiusPI_2());
        cardioid.setA(20);
        CHECK(cardioid.getRadius(M_PI_2) == Approx(40));
        CHECK(cardioid.getRadius(M_PI_2) == cardioid.getRadiusPI_2());
        cardioid.setA(-20);
        CHECK(cardioid.getRadius(M_PI_2) == Approx(-40));
        CHECK(cardioid.getRadius(M_PI_2) == cardioid.getRadiusPI_2());
        cardioid.setA(0);
        CHECK(cardioid.getRadius(M_PI_2) == Approx(0));
        CHECK(cardioid.getRadius(M_PI_2) == cardioid.getRadiusPI_2());
        cardioid.setA(-10.05);
        CHECK(cardioid.getRadius(M_PI_2) == Approx(-20.1));
        CHECK(cardioid.getRadius(M_PI_2) == cardioid.getRadiusPI_2());
    }SECTION("check PI/4 angel radius") {
        cardioid.setA(10);
        CHECK(cardioid.getRadius(M_PI_4) == cardioid.getRadiusPI_4());
        cardioid.setA(20);
        CHECK(cardioid.getRadius(M_PI_4) == cardioid.getRadiusPI_4());
        cardioid.setA(-20);
        CHECK(cardioid.getRadius(M_PI_4) == cardioid.getRadiusPI_4());
        cardioid.setA(0);
        CHECK(cardioid.getRadius(M_PI_4) == cardioid.getRadiusPI_4());
        cardioid.setA(-10.05);
        CHECK(cardioid.getRadius(M_PI_4) == cardioid.getRadiusPI_4());
    }
    SECTION("check max radius") {
        cardioid.setA(10);
        CHECK(cardioid.getMaxRadius() == Approx(40));
        CHECK(cardioid.getMaxRadius() == cardioid.getRadiusPI());
        cardioid.setA(20);
        CHECK(cardioid.getMaxRadius() == Approx(80));
        CHECK(cardioid.getMaxRadius() == cardioid.getRadiusPI());
        cardioid.setA(-20);
        CHECK(cardioid.getMaxRadius() == Approx(-80));
        CHECK(cardioid.getMaxRadius() == cardioid.getRadiusPI());
        cardioid.setA(0);
        CHECK(cardioid.getMaxRadius() == Approx(0));
        CHECK(cardioid.getMaxRadius() == cardioid.getRadiusPI());
        cardioid.setA(-10.05);
        CHECK(cardioid.getMaxRadius() == Approx(-40.2));
        CHECK(cardioid.getMaxRadius() == cardioid.getRadiusPI());
    }
}

TEST_CASE("area and length", "[cardioid]") {
    Cardioid cardioid = Cardioid(10);
    REQUIRE(cardioid.getA() == 10);
    SECTION("check area") {
        CHECK(cardioid.getArea() == 600 * M_PI);
        cardioid.setA(20);
        CHECK(cardioid.getArea() == 2400 * M_PI);
        cardioid.setA(-20);
        CHECK(cardioid.getArea() == 2400 * M_PI);
        cardioid.setA(0);
        CHECK(cardioid.getArea() == 0);
    }SECTION("check length") {
        cardioid.setA(10);
        CHECK(cardioid.getLength(0) == 0);
        CHECK(cardioid.getLength(2 * M_PI) == 320);
        CHECK(cardioid.getLength(M_PI) == 160);
        CHECK(cardioid.getLength(M_PI_2) == 80);
        cardioid.setA(20);
        CHECK(cardioid.getLength(0) == 0);
        CHECK(cardioid.getLength(2 * M_PI) == 640);
        CHECK(cardioid.getLength(M_PI) == 320);
        CHECK(cardioid.getLength(M_PI_2) == 160);
        cardioid.setA(-20);
        CHECK(cardioid.getLength(0) == 0);
        CHECK(cardioid.getLength(2 * M_PI) == 640);
        CHECK(cardioid.getLength(M_PI) == 320);
        CHECK(cardioid.getLength(M_PI_2) == 160);
        cardioid.setA(0);
        CHECK(cardioid.getLength(0) == 0);
        CHECK(cardioid.getLength(2 * M_PI) == 0);
        CHECK(cardioid.getLength(M_PI) == 0);
        CHECK(cardioid.getLength(M_PI_2) == 0);
        cardioid.setA(5.5);
        CHECK(cardioid.getLength(0) == Approx(0));
        CHECK(cardioid.getLength(2 * M_PI) == Approx(176));
        CHECK(cardioid.getLength(M_PI) == Approx(88));
        CHECK(cardioid.getLength(M_PI_2) == Approx(44));
    }
}

