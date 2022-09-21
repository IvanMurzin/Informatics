#include "Scanner.h"
#include "MatrixController.h"
#include <iostream>

int main() {
    MatrixController matrixController;
    Scanner in = Scanner(std::cin);
    while (true) {
        std::cout << "0. Exit program." << std::endl;
        std::cout << "1. Add item." << std::endl;
        std::cout << "2. Show matrix." << std::endl;
        std::cout << "3. Create palindrome matrix" << std::endl;
        int selected = in.nextInt(0, 3, "Enter your command: ");
        switch (selected) {
            case 0:
                std::cout << "Bye." << std::endl;
                return 0;
            case 1:
                matrixController.addElement();
                break;
            case 2:
                matrixController.showList();
                break;
            case 3:
                matrixController.makeNewMatrix();
                break;
        }
    }
}
