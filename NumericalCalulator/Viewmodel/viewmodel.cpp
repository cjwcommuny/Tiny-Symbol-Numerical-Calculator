#include "viewmodel.h"

Viewmodel::Viewmodel(): get_expression_command(std::make_shared<getExpressionCommand>(this))
{

}

std::shared_ptr<Command> Viewmodel::get_expression_command()
{
    return get_expression_command;
}

void Viewmodel::exec_get_expression_command(QString str)
{
    model->transmit_expression(str);
}
