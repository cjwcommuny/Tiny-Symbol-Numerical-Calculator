#include "notification.h"

void OutputNumericalResultNotification_viewmodel::OnPropertyChanged(const std::string& str)
{
    if (str == "ResultGenerated") {
        _viewmodel->Fire_OnPropertyChanged(str);
    }
}

void OutputNumericalResultNotification_view::OnPropertyChanged(const std::string &str)
{
    if (str == "ResultGenerated") {
        std::shared_ptr<std::string> result = _view->getResult();
        assert(result);
        _view->ChangeOutputResultText(*result);
    }
}
