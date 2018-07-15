#include "app.h"

App::App(): view(new View), viewmodel(new Viewmodel), model(new Model)
{

}

void App::run()
{
    model->AddPropertyNotification(viewmodel->notification);//bind notification
    viewmodel->AddPropertyNotification(view->notification);//bind notification
    view->set_getExpressionCommand(std::static_pointer_cast<Command, getExpressionCommand>(std::make_shared<getExpressionCommand>(viewmodel.get())));
    viewmodel->bind(model);
    viewmodel->setResult(model->getExpression());
    view->setResult(viewmodel->getResult());
    view->show();
}
