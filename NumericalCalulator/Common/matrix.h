#ifndef MATRIX_H
#define MATRIX_H
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template<typename T, typename sizeT = size_t>
class matrix
{
private:
    vector <vector<T>> data;
    sizeT nRow;
    sizeT nCol;

public:
    matrix();
    //getter
    sizeT getRow()
    {
        return nRow;
    }
    sizeT getCol()
    {
        return nCol;
    }
    //setter
    void setRow(sizeT r)
    {
        nRow = r;
    }
    void setCol(sizeT c)
    {
        nCol = c;
    }
    void setData(vector<T> tVec)
    {
        data.push_back(tVec);
    }
    T getData(int i, int j)
    {
        return data[i][j];
    }
};

#endif // MATRIX_H
