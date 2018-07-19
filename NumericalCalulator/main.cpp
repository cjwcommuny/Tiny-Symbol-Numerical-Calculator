#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"
#include "Common/matrix.h"
#include "Algorithm/generalparser.h"
#include "Algorithm/matrixtransformation.h"
#include "Algorithm/solvelinear.h"

int main(int argc, char *argv[])
{
    /*
    std::cout << "=============start test==========" << std::endl;
    std::string str("x^2 + x + 1");
    LinkList l(str);
    l.get();
    std::cout << "============= parser end===========" << std::endl;
    vector<Point> po = generatePolynomialPoint(l, 0, 400, 1, 400, 300);
    std::cout << "============= generate end===========" << std::endl;
    for (auto iter = po.begin(); iter != po.end(); ++iter) {
        std::cout << iter->getX() << " " << iter->getY() << std::endl;
    }

    std::cout << "=============end test==========" << std::endl;
*/
    /*
    std::cout << "=============start test==========" << std::endl;
    std::string inputStr("ComputeDeterminant([[1,2];[3,4]])");
    //std::cin >> inputStr;
    std::cout << "=============get input==========" << std::endl;
    inputStr = generalParser(inputStr);
    std::cout << inputStr << std::endl;
    std::cout << "=============test end==========" << std::endl;
    */

    // test inversion
    /*
    std::shared_ptr<matrix> mat = matrixParser("[[1,2];[3,4]]");
    std::cout << "============" << std::endl;
    std::cout << mat->toString() << " "  << std::endl;
    std::cout << "=======" << std::endl;
    std::shared_ptr<matrix> mat2 = matrixInverse(*mat);
    std::string resultStr = mat2->toString();
    std::cout << "============" << std::endl;
    std::cout << resultStr << " "  << std::endl;
    std::cout << "=======" << std::endl;
    */
    /*
    //test transpose
    /*
    std::shared_ptr<matrix> mat = matrixParser("[[1,2];[3 4]  ]");
    std::cout << "============" << std::endl;
    std::cout << mat->toString() << " "  << std::endl;
    std::cout << "=======" << std::endl;
    std::shared_ptr<matrix> mat2 = matrixTranspose(*mat);
    std::cout << "========transpose end" << std::endl;
    std::string resultStr = mat2->toString();
    std::cout << "============" << std::endl;
    std::cout << resultStr << " "  << std::endl;
    std::cout << "=======" << std::endl;
    */

    //test simple expression
    /*
    std::shared_ptr<matrix> M1(new matrix(100, 100));
    std::shared_ptr<matrix> M2(new matrix(100, 100));
    char result = simpleExpressionParser("[1,2]+[2,3]     ", M1, M2);
    std::cout<<"result = "<<result<<endl;
    //std::cout<<M1->getRow()<<endl;
    std::cout<<M1->toString()<<endl;
    std::cout<<M2->toString()<<endl;
    */

    //test LUdecompose
    std::shared_ptr<matrix> M(new matrix(100, 100));
    std::shared_ptr<matrix> b(new matrix(100, 100));
    std::shared_ptr<matrix> x(new matrix(100, 100));
    M->setRow(4);
    M->setCol(4);
    M->setDataSingle(5, 0, 0);
    M->setDataSingle(7, 0, 1);
    M->setDataSingle(6, 0, 2);
    M->setDataSingle(5, 0, 3);

    M->setDataSingle(7, 1, 0);
    M->setDataSingle(10, 1, 1);
    M->setDataSingle(8, 1, 2);
    M->setDataSingle(7, 1, 3);

    M->setDataSingle(6, 2, 0);
    M->setDataSingle(8, 2, 1);
    M->setDataSingle(10, 2, 2);
    M->setDataSingle(9, 2, 3);
    
    M->setDataSingle(5, 3, 0);
    M->setDataSingle(7, 3, 1);
    M->setDataSingle(9, 3, 2);
    M->setDataSingle(10, 3, 3);

    b->setRow(4);
    b->setCol(1);
    b->setDataSingle(1, 0, 0);
    b->setDataSingle(-1, 1, 0);
    b->setDataSingle(-1, 2, 0);
    b->setDataSingle(1, 3, 0);

    x = LUdecompose(M, b);
    x->print();

    /*
    QApplication a(argc, argv);
    App *app = new App();
    app->run();
    return a.exec();
    */
}


