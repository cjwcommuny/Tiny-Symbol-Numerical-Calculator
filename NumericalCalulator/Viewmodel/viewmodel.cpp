#include "viewmodel.h"

Viewmodel::Viewmodel(): get_expression_command(std::make_shared<getExpressionCommand>(this)), notification(std::make_shared<OutputNumericalResultNotification_viewmodel>(this))
{

}

void Viewmodel::exec_get_expression_command(std::string str)
{
    _model->transmit_expression(str);
}

void Viewmodel::notify(std::string str)
{
    Fire_OnPropertyChanged(str);
}

std::shared_ptr<std::string> Viewmodel::getResult()
{
    //result = _model->getExpression();
    return result;
}
