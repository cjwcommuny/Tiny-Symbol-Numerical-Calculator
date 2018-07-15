#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "lib/etlbase.h"
#include "View/view.h"
#include "Viewmodel/viewmodel.h"

class Viewmodel;
class View;

class OutputNumericalResultNotification_viewmodel: public IPropertyNotification
{
public:
    OutputNumericalResultNotification_viewmodel(Viewmodel *viewmodel): _viewmodel(viewmodel) {}
    void OnPropertyChanged(const std::string& str);
private:
    Viewmodel *_viewmodel;
};




class OutputNumericalResultNotification_view: public IPropertyNotification
{
public:
    std::string resultStr;

    OutputNumericalResultNotification_view(View *view): _view(view) {}
    void OnPropertyChanged(const std::string& str);
private:
    View *_view;
};

#endif // NOTIFICATION_H
