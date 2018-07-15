#include "outputnumericalresultnotification_viewmodel.h"

void OutputNumericalResultNotification_viewmodel::OnPropertyChanged(const std::string& str)
{
    if (str == "ResultGenerated") {
        _viewmodel->Fire_OnPropertyChanged(str);
    }
}
