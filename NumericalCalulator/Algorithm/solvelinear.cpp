#include "Algorithm/solvelinear.h"

shared_ptr<matrix> LUdecompose(shared_ptr<matrix> &M, shared_ptr<matrix> &b)
{
    size_t n = M->getRow();

    shared_ptr<matrix> L(new matrix(100, 100));
    shared_ptr<matrix> U(new matrix(100, 100));
    shared_ptr<matrix> y(new matrix(100, 100));
    shared_ptr<matrix> x(new matrix(100, 100));

    L->setRow(n);
    L->setCol(n);
    U->setRow(n);
    U->setCol(n);
    y->setRow(n);
    y->setCol(1);
    x->setRow(n);
    x->setCol(1);

    //初始化L、U矩阵
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            U->setDataSingle(0, i, j);
            if(i == j)
            {
                L->setDataSingle(1, i, j);
            }
            else
                L->setDataSingle(0, i, j);
        }
    }

    for(size_t k = 0; k < n; k++)
    {
        for(size_t j = k; j < n; j++)  //求U中第k行元素
        {
            U->setDataSingle(M->getData(k, j), k, j);
            for(size_t r = 0; r < k; r++)
            {
                U->setDataSingle(U->getData(k, j) - L->getData(k, r)*U->getData(r, j), k, j);
            }
        }
        for(size_t i = k + 1; i < n; i++) //求L中第k列元素
        {
            L->setDataSingle(M->getData(i, k), i, k);
            for(size_t r = 0; r < k; r++)
            {
                L->setDataSingle(L->getData(i, k) - L->getData(i, r)*U->getData(r, k), i, k);
            }
            L->setDataSingle(L->getData(i, k)/U->getData(k, k), i, k);
        }
    }
    //由Ly = b 求出y[i]
    for(size_t i = 0; i < n; i++)
    {
        y->setDataSingle(b->getData(i, 0), i, 0);
        for(size_t j = 0; j < i; j++)
        {
            y->setDataSingle(y->getData(i, 0) - L->getData(i, j)*y->getData(j, 0), i, 0);
        }
    }

    //由 Ux=y 求出 x[i]
    for(size_t i = n - 1; i > 0; i--)
    {
        x->setDataSingle(y->getData(i, 0), i, 0);
        for(size_t j = i + 1; j < n; j++)
        {
            y->setDataSingle(y->getData(i, 0) - U->getData(i, j)*x->getData(j, 0), i, 0);
        }
        x->setDataSingle(y->getData(i, 0)/U->getData(i, i), i, 0);
    }
    x->setDataSingle(y->getData(0, 0), 0, 0);
    for(size_t j = 1; j < n; j++)
        y->setDataSingle(y->getData(0, 0) - U->getData(0, j)*x->getData(j, 0), 0, 0);
    x->setDataSingle(y->getData(0, 0)/U->getData(0, 0), 0, 0);

    return x;
}
