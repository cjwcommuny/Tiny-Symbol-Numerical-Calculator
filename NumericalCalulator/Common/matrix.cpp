#include "matrix.h"

template <typename T, typename sizeT = size_t>
matrix::matrix(T a): data({{a}}), nRow(1), nCol(1)
{

}

template <typename T, typename sizeT>
matrix::matrix(sizeT row, sizeT col): data(vector<vector<T>>(row, vector<T>(col))), nRow(row), nCol(col)
{

}

template <typename T, typename sizeT = size_t>
matrix<T> matrix::operator*(matrix<T> lMatrix, matrix<T> rMatrix)
{
    matrix<T> resultMatrix(lMatrix.getRow(), rMatrix.getCol());
    if (lMatrix.getCol() != rMatrix.getRow()) {
        //cannot multiply
    } else {
        for (sizeT i = 0; i < lMatrix.getRow(); ++i) {
            for (sizeT j = 0; j < rMatrix.getCol(); ++j) {//for every cell in the result matrix
                for (sizeT k = 0; k < lMatrix.getCol(); ++k) {
                    resultMatrix.data[i,j] += lMatrix.data[i, k] * rMatrix.data[j, k];
                }
            }
        }
        return resultMatrix;
    }
}

template <typename T, typename sizeT = size_t>
matrix<T> matrix::operator+(matrix<T> lMatrix, matrix<T> rMatrix)
{
    matrix<T> resultMatrix(lMatrix.getRow(), rMatrix.getCol());
    if (lMatrix.getRow() != rMatrix.getRow() || lMatrix.getCol() != rMatrix.getCol()) {
        //cannot add
    } else {
        for (sizeT i = 0; i < resultMatrix.getRow(); ++i) {
            for (sizeT j = 0; j < resultMatrix.getCol(); ++j) {
                resultMatrix.data[i,j] = lMatrix.data[i,j] + rMatrix.data[i,j];
            }
        }
        return resultMatrix;
    }
}

template <typename T, typename sizeT = size_t>
matrix<T> matrix::operator-(matrix<T> lMatrix, matrix<T> rMatrix)
{
    matrix<T> resultMatrix(lMatrix.getRow(), rMatrix.getCol());
    if (lMatrix.getRow() != rMatrix.getRow() || lMatrix.getCol() != rMatrix.getCol()) {
        //cannot add
    } else {
        for (sizeT i = 0; i < resultMatrix.getRow(); ++i) {
            for (sizeT j = 0; j < resultMatrix.getCol(); ++j) {
                resultMatrix.data[i,j] = lMatrix.data[i,j] - rMatrix.data[i,j];
            }
        }
        return resultMatrix;
    }
}