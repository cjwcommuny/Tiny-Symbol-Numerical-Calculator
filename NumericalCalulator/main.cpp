#include <QApplication>
#include "App/app.h"
//#include "lib/Eigen/Dense"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App *app = new App();
    app->run();

    return a.exec();
}
