#ifndef APP_H
#define APP_H

#include <QMainWindow>

class App
{
public:
    App();
    run();
private:
    std::shared_ptr<View> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<Mainwindow> mainwindow;
};

#endif // APP_H
