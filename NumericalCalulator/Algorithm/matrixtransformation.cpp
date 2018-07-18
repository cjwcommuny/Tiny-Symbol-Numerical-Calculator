#include "Algorithm/matrixtransformation.h"
using namespace std;
#define MAX 100

shared_ptr<matrix> matrixTranspose(matrix &M)
{
    shared_ptr<matrix> mptr(new matrix(M.getCol(), M.getRow()));
    std::cout << "======" << mptr->getRow() << " " << mptr->getCol() << std::endl;
    for(int i = 0; i < M.getRow(); i++)
        for (int j = 0; j < M.getCol(); j++) {
            mptr->setDataSingle(M.getData(i, j), j, i);
        }
    return mptr;
}

shared_ptr<matrix> matrixInverse(matrix &M)
{
    if (M.getRow() != M.getCol())
        return NULL;
    size_t total = M.getCol();
    //vector <size_t> is(total + 1);
    //vector <size_t> js(total + 1);
    int is[MAX];
    int js[MAX];
    int u, v;
    int f = 1;
    double det = 1;

    for (int k = 0; k < total; k++)
    {
        double max = 0;
        for (int i = k; i < total; ++i)
        {
            for (int j = k; j < total; ++j)
            {
                const double f = fabs(M.getData(i, j));
                if (f > max)
                {
                    max = f;
                    is[k] = i;
                    js[k] = j;
                }
            }
        }
        if (fabs(max) < 0.00001f)
            return NULL;
        if (is[k] != k)
        {
            f = -f;
            for (v = 0; v < total; v++)
            {
                double tem = M.getData(k, v);
                M.setDataSingle(M.getData(is[k], v), k, v);
                M.setDataSingle(tem, is[k], v);
            }
        }
        if (js[k] != k)
        {
            f = -f;
            for (v = 0; v < total; v++)
            {
                double tem = M.getData(v, k);
                M.setDataSingle(M.getData(v, js[k]), v, k);
                M.setDataSingle(tem, v, js[k]);
            }
        }

        //计算行列值
        det *= M.getData(k, k);

        //计算逆矩阵
        M.setDataSingle(1.0f / M.getData(k, k), k, k);

        for (u = 0; u < total; ++u)
        {
            if (u != k)
                M.setDataSingle(M.getData(k, u)*M.getData(k, k), k, u);
        }

        for (int i = 0; i < total; ++i)
        {
            if (i != k)
            {
                for (int j = 0; j < total; ++j)
                {
                    if (j != k)
                        M.setDataSingle(M.getData(i, j) - M.getData(i, k)*M.getData(k, j), i, j);
                }
            }
        }

        for (int i = 0; i < total; ++i)
        {
            if (i != k)
                M.setDataSingle(M.getData(i, k) * -M.getData(k, k), i, k);
        }
    }

    for (int k = total - 1; k >= 0; --k)
    {
        if (js[k] != k)
        {
            for (int i = 0; i < total; i++)
            {
                double tem = M.getData(k, i);
                M.setDataSingle(M.getData(js[k], i), k, i);
                M.setDataSingle(tem, js[k], i);
            }
        }
        if (is[k] != k)
        {
            for (int i = 0; i < total; i++)
            {
                double tem = M.getData(i, k);
                M.setDataSingle(M.getData(i, is[k]), i, k);
                M.setDataSingle(tem, i, is[k]);
            }
        }
    }
    double value = det * f;
    shared_ptr<matrix> mptr(new matrix(MAX, MAX));
    /*
    mptr->setRow(M.getRow());
    mptr->setCol(M.getCol());
    for(u = 0; u < M.getRow(); u++)
        for (v = 0; v < M.getRow(); v++)
        {
            mptr->setDataSingle(M.getData(u, v), u, v);
        }
    */
    return mptr;
}
