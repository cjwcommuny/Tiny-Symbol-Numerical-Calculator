#include "computedeterminant.h"


matrix GenerateMinor(const matrix &sourceMatrix, size_t i, size_t j)
{
    matrix result = matrix(sourceMatrix.getRow() - 1, sourceMatrix.getCol() - 1);
    for (size_t k = 0; k < i; ++k) {
        for (size_t l = 0; l < j; ++l) {
            result.setDataSingle(sourceMatrix.getData(k, l), k, l);
        }
    }

    for (size_t k = i + 1; k < sourceMatrix.getRow(); ++k) {
        for (size_t l = 0; l < j; ++l) {
            result.setDataSingle(sourceMatrix.getData(k, l), k - 1, l);
        }
    }

    for (size_t k = 0; k < i; ++k) {
        for (size_t l = j + 1; l < sourceMatrix.getCol(); ++l) {
            result.setDataSingle(sourceMatrix.getData(k, l), k, l - 1);
        }
    }

    for (size_t k = i + 1; k < sourceMatrix.getRow(); ++k) {
        for (size_t l = j + 1; l < sourceMatrix.getCol(); ++l) {
            result.setDataSingle(sourceMatrix.getData(k, l), k - 1, l - 1);
        }
    }
    return result;
}



double ComputeDeterminant(const matrix &sourceMatrix)
{
    double result = 0;
    if (sourceMatrix.getCol() != sourceMatrix.getRow()) {
        //don't have determinant
    } else if (sourceMatrix.getRow() == 1) {
        return sourceMatrix.getData(0,0);
    } else {
        int symbol = 1;
        for (size_t index = 0; index < sourceMatrix.getCol(); ++index) {
            result += symbol * sourceMatrix.getData(0, index) * ComputeDeterminant(GenerateMinor(sourceMatrix, 0, index));
            symbol = - symbol;
        }
        return result;
    }
}
