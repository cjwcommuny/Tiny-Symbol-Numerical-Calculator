#ifndef MATRIX_H
#define MATRIX_H
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class matrix
{
private:
    vector <vector<double>> data;
    size_t nRow;
    size_t nCol;

public:
    matrix() = default;
    matrix(size_t row, size_t col): data(vector<vector<double>>(row, vector<double>(col))), nRow(row), nCol(col) {}
    //getter
    size_t getRow() const
    {
        return nRow;
    }
    size_t getCol() const
    {
        return nCol;
    }
    //setter
    void setRow(size_t r)
    {
        nRow = r;
    }
    void setCol(size_t c)
    {
        nCol = c;
    }
    void setData(vector<double> tVec)
    {
        data.push_back(tVec);
    }
    double getData(int i, int j) const
    {
        return data[i][j];
    }

    void setDataSingle(double t, size_t i, size_t j)
    {
        data[i][j] = t;
    }

    std::string toString()
    {
        std::stringstream ss;
        for (size_t i = 0; i < getRow(); ++i) {
            for (size_t j = 0; j < getCol(); ++j) {
                ss << data[i][j] << " ";
            }
            ss << '\n';
        }
        return ss.str();
    }

    friend matrix operator*(matrix lMatrix, matrix rMatrix);

    friend matrix operator+(matrix lMatrix, matrix rMatrix);

    friend matrix operator-(matrix lMatrix, matrix rMatrix);
};

#endif // MATRIX_H
