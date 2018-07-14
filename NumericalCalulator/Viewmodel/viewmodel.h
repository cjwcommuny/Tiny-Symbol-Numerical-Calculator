#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "Model/model.h"
#include <memory>
#include "Parameter/parameter.h"
#include "Viewmodel/Command/command.h"
#include "lib/etlbase.h"
#include "Notification/notification.h"

class Viewmodel: Proxy_PropertyNotification<Viewmodel>
{
public:
    Viewmodel();
    void bind(std::shared_ptr<Model> model) {_model = model;}

    void exec_get_expression_command(QString str);
protected:

private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<Command> get_expression_command;

    //execute command
    std::shared_ptr<Command> get_expression_command();

    //notification
    OutputNumericalResultNotification_viewmodel notification;
    void notify(std::string str);
};

#endif // VIEWMODEL_H
