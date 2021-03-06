#include "app.h"
#include "ui_curveform.h"

App::App(): view(new View), viewmodel(new Viewmodel), model(new Model)
{

}

void App::run()
{
    viewmodel->bind(model);
    viewmodel->AddPropertyNotification(view->getNotification());//bind notification
    //viewmodel->AddPropertyNotification(view->getUi()->curveGraphView->getNotification());
    viewmodel->AddCommandNotification(view->getNotificationError());
    view->set_getExpressionCommand(std::static_pointer_cast<Command, getExpressionCommand>(std::make_shared<getExpressionCommand>(viewmodel.get())));

    view->setResult(viewmodel->getResult());
    view->setVertexArr(viewmodel->getVertexArr());
    view->show();
}
