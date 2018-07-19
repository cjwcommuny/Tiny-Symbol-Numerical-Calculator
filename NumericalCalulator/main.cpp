#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"
#include "Common/matrix.h"
#include "Algorithm/generalparser.h"
#include "Algorithm/matrixtransformation.h"

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
<<<<<<< HEAD

=======
    /*
>>>>>>> chenjiawei
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

<<<<<<< HEAD
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

    /*
=======
    
>>>>>>> chenjiawei
    QApplication a(argc, argv);
    App *app = new App();
    app->run();
    return a.exec();
<<<<<<< HEAD
    */
=======

>>>>>>> chenjiawei
}


