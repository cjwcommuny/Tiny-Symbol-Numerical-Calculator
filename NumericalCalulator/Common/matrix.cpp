#include "matrix.h"
#include "Common/exception.h"


matrix operator*(matrix lMatrix, matrix rMatrix)
{
    matrix resultMatrix(lMatrix.getRow(), rMatrix.getCol());
    if (lMatrix.getCol() != rMatrix.getRow()) {
        throw MatrixNotCompatibleException();
    } else {
        for (size_t i = 0; i < lMatrix.getRow(); ++i) {
            for (size_t j = 0; j < rMatrix.getCol(); ++j) {//for every cell in the result matrix
                for (size_t k = 0; k < lMatrix.getCol(); ++k) {
                    resultMatrix.data[i][j] += lMatrix.getData(i, k) * rMatrix.getData(k, j);
                }
            }
        }
        return resultMatrix;
    }
}



matrix operator+(matrix lMatrix, matrix rMatrix)
{
    matrix resultMatrix(lMatrix.getRow(), rMatrix.getCol());
    if (lMatrix.getRow() != rMatrix.getRow() || lMatrix.getCol() != rMatrix.getCol()) {
        throw MatrixNotCompatibleException();
    } else {
        for (size_t i = 0; i < resultMatrix.getRow(); ++i) {
            for (size_t j = 0; j < resultMatrix.getCol(); ++j) {
                resultMatrix.data[i][j] = lMatrix.getData(i,j) + rMatrix.getData(i,j);
            }
        }
        return resultMatrix;
    }
}

matrix operator-(matrix lMatrix, matrix rMatrix)
{
    matrix resultMatrix(lMatrix.getRow(), rMatrix.getCol());
    if (lMatrix.getRow() != rMatrix.getRow() || lMatrix.getCol() != rMatrix.getCol()) {
        throw MatrixNotCompatibleException();
    } else {
        for (size_t i = 0; i < resultMatrix.getRow(); ++i) {
            for (size_t j = 0; j < resultMatrix.getCol(); ++j) {
                resultMatrix.data[i][j] = lMatrix.getData(i,j) - rMatrix.getData(i,j);
            }
        }
        return resultMatrix;
    }
}

void matrix::splitByCol(size_t col, matrix &mat1, matrix &mat2) const//the number of columns of the left matrix is col
{
    std::cout << "enter split function" << std::endl;
    matrix matLeft(getRow(), col);
    matrix matRight(getRow(), getCol() - col);
    for (auto i = 0; i < getRow(); ++i) {
        for (auto j = 0; j < getCol(); ++j) {
            if (j < col) {//left matrix
                std::cout << "left: " << i << " " << j << std::endl;
                matLeft.setDataSingle(data[i][j], i, j);
            } else {
                std::cout << "left: " << i << " " << j << std::endl;
                matRight.setDataSingle(data[i][j], i, j - col);
            }
        }
    }
    mat1 = matLeft;
    mat2 = matRight;
}