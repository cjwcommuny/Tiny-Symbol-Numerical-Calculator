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
        _view->ChangeOutputResultText(str);
    }
}
