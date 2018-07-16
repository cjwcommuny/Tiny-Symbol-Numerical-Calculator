
#include "Viewmodel/viewmodel.h"

Viewmodel::Viewmodel():
    get_expression_command(std::make_shared<getExpressionCommand>(this)),
    notification(std::make_shared<OutputNumericalResultNotification_viewmodel>(this))
{

}

bool Viewmodel::process_expression(std::string str)
{
    return _model->transmit_expression(str);
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

void Viewmodel::bind(std::shared_ptr<Model> model)
{
    _model = model;
    result = _model->getExpression();
    _model->AddPropertyNotification(notification);//bind notification
}
