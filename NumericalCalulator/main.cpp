/*#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"

int main(int argc, char *argv[])
{

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
