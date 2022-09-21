#pragma once

#include "Matrix.h"

class MatrixController {
private:
    Matrix matrix;
    Matrix newMatrix;

    void showMatrixList(const Matrix &currentMatrix) const;

public:
    MatrixController();

    void addElement();

    void showList() const;

    void makeNewMatrix();
};