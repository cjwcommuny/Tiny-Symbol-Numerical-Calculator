#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "Model/model.h"
#include <memory>
#include "Parameter/parameter.h"
#include "Viewmodel/Command/command.h"
#include "lib/etlbase.h"
#include "Notification/notification.h"
#include "View/view.h"

class Viewmodel: Proxy_PropertyNotification<Viewmodel>
{
public:
    Viewmodel();
    void bind(std::shared_ptr<Model> model, std::shared_ptr<View> view) {_model = model; _view = view;}

protected:

private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<View> _view;
    std::shared_ptr<Command> get_expression_command;

    //execute command
    std::shared_ptr<Command> get_expression_command();

    //notification
    OutputNumericalResultNotification_viewmodel notification;
    void notify(std::string str);
};

#endif // VIEWMODEL_H
