#include "Viewmodel/Command/getexpressioncommand.h"
#include "Viewmodel/viewmodel.h"

void getExpressionCommand::Exec()
{
    if (viewmodel->process_expression(*std::static_pointer_cast<StringParameter>(parameter)) == false) {
        viewmodel->Fire_OnCommandComplete("ResultGenerated", false);
    } else {
        viewmodel->Fire_OnCommandComplete("ResultGenerated", true);
    }
}
