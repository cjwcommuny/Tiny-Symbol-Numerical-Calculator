#include "app.h"

App::App(): view(new View), viewmodel(new Viewmodel), model(new Model)
{

}

void App::run()
{
    viewmodel->bind(model);
    viewmodel->AddPropertyNotification(view->getNotification());//bind notification
    viewmodel->AddCommandNotification(view->getNotificationError());
    view->set_getExpressionCommand(std::static_pointer_cast<Command, getExpressionCommand>(std::make_shared<getExpressionCommand>(viewmodel.get())));

    view->setResult(viewmodel->getResult());
    view->show();
}
