#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"
#include "Algorithm/generalparser.h"

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

    QApplication a(argc, argv);
    App *app = new App();
    app->run();
    return a.exec();
}


