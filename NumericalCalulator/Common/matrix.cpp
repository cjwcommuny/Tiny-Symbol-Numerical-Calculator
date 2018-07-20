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
                    resultMatrix.data[i][j] += lMatrix.getData(i, k) * rMatrix.getData(j, k);
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
