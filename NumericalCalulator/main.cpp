/*#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    App *app = new App();
    app->run();

    return a.exec();
}*/
#include"common/polynomial.h"
#include"Algorithm/niudun.h"
int main()
{
    LinkList polynominal("x^2-x = 0");
    polynominal.print();
    cout<<niudun(polynominal);
}

