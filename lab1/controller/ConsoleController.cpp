#include "ConsoleController.h"
#include "Scanner.h"

namespace ConsoleController {
    Matrix readMatrixStd() {
        std::cout << " ----------Input Matrix---------- " << std::endl;
        Scanner in = Scanner(std::cin);
        int n = in.nextInt(1, 10000, "Input n: ");
        int m = in.nextInt(1, 10000, "Input m: ");
        return Matrix(n, m);
    }

    Item readItemStd(int maxX, int maxY) {
        Scanner in = Scanner(std::cin);
        int x = in.nextInt(0, maxX, "Input x: ");
        int y = in.nextInt(0, maxY, "Input y: ");
        int data = in.nextInt(0,"Input data: ");
        return Item(x, y, data);
    }
}