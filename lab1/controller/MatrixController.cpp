#include "MatrixController.h"
#include "ConsoleController.h"


MatrixController::MatrixController() : matrix(ConsoleController::readMatrixStd()) {}

void MatrixController::addElement() {
    Item item = ConsoleController::readItemStd(matrix.getN() - 1, matrix.getM() - 1);
    matrix.addItem(std::move(item));
}


void MatrixController::showList() const {
    std::cout << std::endl << "Matrix list" << std::endl;
    showMatrixList(matrix);
    std::cout << "New matrix list" << std::endl;
    showMatrixList(newMatrix);
    std::cout << std::endl;
}

void MatrixController::makeNewMatrix() {
    newMatrix.makePalindrome(matrix);
}

void MatrixController::showMatrixList(const Matrix &currentMatrix) const {
    List<Line>::Iterator iterator = currentMatrix.getData().begin();
    while (iterator != currentMatrix.getData().end()) {
        std::cout << "Line: y = " << (*iterator).getIndex() << ":";
        auto itemIterator = (*iterator).getItems().begin();
        while (itemIterator != (*iterator).getItems().end()) {
            std::cout << " x = " << (*itemIterator).getX() << " data = " << (*itemIterator).getData() << "; ";
            ++itemIterator;
        }
        std::cout << std::endl;
        ++iterator;
    }
}
