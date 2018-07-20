#include "Notification/outputerrornotification_view.h"
#include "View/view.h"

void OutputErrorNotification_view::OnCommandComplete(const std::string& str, bool bOK)
{
    if (str == "ResultGenerated") {
        if (bOK == false) {
            _view->ChangeOutputResultText(*(_view->getResult()));
        } else {
            //generate success, do nothing
        }
    }
}
