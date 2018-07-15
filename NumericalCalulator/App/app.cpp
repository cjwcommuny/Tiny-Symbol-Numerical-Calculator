#include "app.h"

App::App(): view(new View), viewmodel(new Viewmodel), model(new Model)
{

}

void App::run()
{
    //view = new View;
    //model = new Model;
    //viewmodel = new Viewmodel;


    model->AddPropertyNotification(viewmodel->notification);//bind notification
    viewmodel->AddPropertyNotification(view->notification);//bind notification
    std::shared_ptr<getExpressionCommand> view_model = std::make_shared<getExpressionCommand>(viewmodel.get());
    view->set_get_expression_command(std::static_pointer_cast<Command, getExpressionCommand>(view_model));
    view->bind(viewmodel);
    viewmodel->bind(model, view);
    model->bind(viewmodel);

    view->show();
}
