#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"
#include "Common/drawpolynomialcurve.h"

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
    QApplication a(argc, argv);
    App *app = new App();
    app->run();

    return a.exec();

}
