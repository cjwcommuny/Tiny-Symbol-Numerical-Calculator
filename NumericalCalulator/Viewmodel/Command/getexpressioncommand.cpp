#include "Viewmodel/Command/getexpressioncommand.h"

void getExpressionCommand::Exec()
{
    viewmodel->exec_get_expression_command(parameter);
}
