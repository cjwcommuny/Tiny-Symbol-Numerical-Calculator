#include "app.h"

App::App(): view(new View), model(new Model), viewmodel(new Viewmodel)
{

}

void App::run()
{
    //view = new View;
    //model = new Model;
    //viewmodel = new Viewmodel;
    view->set_get_expression_command(std::make_shared<getExpressionCommand>(viewmodel));
    view->bind(viewmodel);
    viewmodel->bind(view, model);
    model->bind(viewmodel);
    view->show();
}
