#include "Notification/outputnumericalresultnotification_viewmodel.h"
#include "Viewmodel/viewmodel.h"

void OutputNumericalResultNotification_viewmodel::OnPropertyChanged(const std::string& str)
{
    if (str == "ResultGenerated") {
        _viewmodel->Fire_OnPropertyChanged(str);
    }
}
