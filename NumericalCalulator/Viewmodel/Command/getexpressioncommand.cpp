#include "Viewmodel/Command/getexpressioncommand.h"

void getExpressionCommand::Exec()
{
    viewmodel->exec_get_expression_command(*std::static_pointer_cast<StringParameter>(parameter));
}
