#include "computedeterminant.h"


template <typename T, typename sizeT = size_t>
matrix<T> GenerateMinor(matrix<T> &sourceMatrix, sizeT i, sizeT j)
{
    matrix<T> result = matrix(sourceMatrix.getRow() - 1, sourceMatrix.getCol() - 1);
    for (sizeT k = 0; k < i; ++k) {
        for (sizeT l = 0; l < j; ++l) {
            result.setDataSingle(sourceMatrix(k, l), k, l);
        }
    }

    for (sizeT k = i + 1; k < sourceMatrix.getRow(); ++k) {
        for (sizeT l = 0; l < j; ++l) {
            result.setDataSingle(sourceMatrix(k, l), k - 1, l);
        }
    }

    for (sizeT k = 0; k < i; ++k) {
        for (sizeT l = j + 1; l < sourceMatrix.getCol(); ++l) {
            result.setDataSingle(sourceMatrix(k, l), k, l - 1);
        }
    }

    for (sizeT k = i + 1; k < sourceMatrix.getRow(); ++k) {
        for (sizeT l = j + 1; l < sourceMatrix.getCol(); ++l) {
            result.setDataSingle(sourceMatrix(k, l), k - 1, l - 1);
        }
    }
    return result;
}

template <typename T, typename sizeT = size_t>
T ComputeSubDeterminant(matrix<T> &sourceMatrix)
{
    if (i == sourceMatrix.getRow() - 1) {//1*1 matrix
        return sourceMatrix.getData(i, j);
    } else {
        int symbol = 1;
        T result = 0;
        for (sizeT index = 0; index < sourceMatrix.getCol(); ++index) {
            result += symbol * sourceMatrix.getData(0, index) * ComputeSubDeterminant(GenerateMinor(sourceMatrix, 0, index));
        }
    }
}

template <typename T, typename sizeT = size_t>
T ComputeDeterminant(matrix<T> &sourceMatrix)
{
    if (sourceMatrix.getCol() != sourceMatrix.getRow()) {
        //don't have determinant
    } else {
        return ComputeSubDeterminant(sourceMatrix);
    }
}
