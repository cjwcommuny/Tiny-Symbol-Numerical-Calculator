#include "app.h"

App::App(): view(new View), model(new Model), viewmodel(new Viewmodel)
{

}

void App::run()
{
    //view = new View;
    //model = new Model;
    //viewmodel = new Viewmodel;
    view->show();
}
