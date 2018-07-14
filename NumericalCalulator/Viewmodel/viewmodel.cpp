#include "viewmodel.h"

Viewmodel::Viewmodel(): get_expression_command(std::make_shared<getExpressionCommand>(this)), notification(make_shared<OutputNumericalResultNotification>())
{
    _model->AddPropertyNotification(notification);//bind notification
}

std::shared_ptr<Command> Viewmodel::get_expression_command()
{
    return get_expression_command;
}

void Viewmodel::exec_get_expression_command(QString str)
{
    model->transmit_expression(str);
}

void Viewmodel::notify(std::string str)
{
    Fire_OnPropertyChanged(str);
}
