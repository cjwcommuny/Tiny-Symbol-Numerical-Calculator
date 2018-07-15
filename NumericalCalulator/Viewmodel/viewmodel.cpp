#include "viewmodel.h"

Viewmodel::Viewmodel(): get_expression_command(std::make_shared<getExpressionCommand>(this)), notification(make_shared<OutputNumericalResultNotification_view>())
{
    AddPropertyNotification(_view->notification);//bind notification
}

void Viewmodel::exec_get_expression_command(QString str)
{
    _model->transmit_expression(str);
}

void Viewmodel::notify(std::string str)
{
    Fire_OnPropertyChanged(str);
}
