#include "Dialog.h"
#include "model/Cardioid.h"

int main() {
    Dialog dialog = Dialog();
    auto cardioid = Cardioid(dialog.getScanner().next<double>("Enter cardioid coefficient a: "));
    dialog.addAction("Print cardioid formula", [&cardioid] { std::cout << cardioid.getFormula() << std::endl; });
    dialog.addAction("Set cardioid coefficient", [&cardioid, &dialog] { cardioid.setA(dialog.getScanner().next<double>("Enter new cardioid coefficient a: ")); });
    dialog.addAction("Get cardioid radius", [&cardioid, &dialog] {
        const auto &in = dialog.getScanner();
        double radius = in.next<double>("Input angel: ");
        std::cout << cardioid.getRadius(radius) << std::endl;
    });
    dialog.addAction("Get max cardioid radius", [&cardioid] { std::cout << cardioid.getMaxRadius() << std::endl; });
    dialog.addAction("Get cardioid radius PI", [&cardioid] { std::cout << cardioid.getRadiusPI() << std::endl; });
    dialog.addAction("Get cardioid radius PI_2", [&cardioid] { std::cout << cardioid.getRadiusPI_2() << std::endl; });
    dialog.addAction("Get cardioid radius PI_4", [&cardioid] { std::cout << cardioid.getRadiusPI_4() << std::endl; });
    dialog.addAction("Get cardioid area", [&cardioid] { std::cout << cardioid.getArea() << std::endl; });
    dialog.addAction("Get cardioid length", [&cardioid, &dialog] {
        const auto &in = dialog.getScanner();
        double radius = in.next<double>("Input angel: ");
        std::cout << cardioid.getLength(radius) << std::endl;
    });
    while (dialog.select());
    return 0;
}