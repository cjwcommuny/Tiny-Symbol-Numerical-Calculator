#include "Notification/outputnumericalresultnotification_view.h"
#include "View/view.h"

void OutputNumericalResultNotification_view::OnPropertyChanged(const std::string &str)
{
    if (str == "ResultGenerated") {
        std::shared_ptr<std::string> result = _view->getResult();
        assert(result);
        _view->ChangeOutputResultText(*result);
    }
}
