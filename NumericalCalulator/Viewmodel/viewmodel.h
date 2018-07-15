#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include <memory>
#include "lib/etlbase.h"
#include "Model/model.h"
#include "Parameter/parameter.h"
#include "Viewmodel/Command/command.h"
#include "Viewmodel/Command/getexpressioncommand.h"
#include "Notification/notification.h"
#include "View/view.h"

class Model;
class View;
class OutputNumericalResultNotification_viewmodel;
class getExpressionCommand;

class Viewmodel: public Proxy_PropertyNotification<Viewmodel>
{
public:
    Viewmodel();
    void bind(std::shared_ptr<Model> model, std::shared_ptr<View> view) {_model = model; _view = view;}
    std::shared_ptr<OutputNumericalResultNotification_viewmodel> notification;
    void exec_get_expression_command(std::string str);
protected:

private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<View> _view;
    std::shared_ptr<getExpressionCommand> get_expression_command;

    //execute command

    //std::shared_ptr<Command> exec_get_expression_command();

    //notification

    void notify(std::string str);
};

#endif // VIEWMODEL_H
