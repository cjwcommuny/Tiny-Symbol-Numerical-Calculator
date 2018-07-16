#ifndef MATRIX_H
#define MATRIX_H
<<<<<<< HEAD
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
=======


class Matrix
{
public:
    Matrix();
>>>>>>> 5ce1cec1d081c58a6e672e29aadc875035c4d560
};

#endif // MATRIX_H
