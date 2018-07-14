#ifndef APP_H
#define APP_H

#include <QMainWindow>
#include "Viewmodel/viewmodel.h"
#include "View/view.h"
#include "Model/model.h"
#include <memory>

class App
{
public:
    App();
    void run();
private:
    std::shared_ptr<Viewmodel> viewmodel;
    std::shared_ptr<Model> model;
    std::shared_ptr<View> view;
};

#endif // APP_H
