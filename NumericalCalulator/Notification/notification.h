#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "lib/etlbase.h"
#include "View/view.h"
#include "Viewmodel/viewmodel.h"

class OutputNumericalResultNotification_viewmodel: public IPropertyNotification
{
public:
    OutputNumericalResultNotification_viewmodel(std::shared_ptr<Viewmodel> viewmodel): _viewmodel(viewmodel) {}
    void OnPropertyChanged(const std::string& str);
private:
    std::shared_ptr<Viewmodel> _viewmodel;
};




class OutputNumericalResultNotification_view: public IPropertyNotification
{
public:
    std::string resultStr;

    OutputNumericalResultNotification_view(std::shared_ptr<View> view): _view(view) {}
    void OnPropertyChanged(const std::string& str);
private:
    std::shared_ptr<View> _view;
}

#endif // NOTIFICATION_H
