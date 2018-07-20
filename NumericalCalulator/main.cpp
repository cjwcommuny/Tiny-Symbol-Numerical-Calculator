#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"
#include "Common/matrix.h"
#include "Algorithm/generalparser.h"
#include "Algorithm/matrixtransformation.h"

int main(int argc, char *argv[])
{
<<<<<<< HEAD

    QApplication a(argc, argv);
    App *app = new App();
    app->run();

    return a.exec();*/
#include"common/polynomial.h"
using namespace std;
#include<stdio.h>
#include<string>
int main()
{
    LinkList L("3.3X^2 - X =1");
    cout<<L.Quadrature()<<endl;
 }
=======
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

    std::shared_ptr<matrix> mat = matrixParser("[[1,2];[3,4]]");
    std::cout << "============" << std::endl;
    std::cout << mat->toString() << " "  << std::endl;
    std::cout << "=======" << std::endl;
    std::shared_ptr<matrix> mat2 = matrixInverse(*mat);
    std::string resultStr = mat2->toString();
    std::cout << "============" << std::endl;
    std::cout << resultStr << " "  << std::endl;
    std::cout << "=======" << std::endl;

    /*
    //test transpose
    std::shared_ptr<matrix> mat = matrixParser("[[1,2];[3,4]]");
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

        /*
    QApplication a(argc, argv);
    App *app = new App();
    app->run();
    return a.exec();
*/
}


>>>>>>> master
