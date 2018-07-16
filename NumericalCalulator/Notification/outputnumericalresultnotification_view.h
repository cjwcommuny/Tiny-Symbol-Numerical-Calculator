#ifndef OUTPUTNUMERICALRESULTNOTIFICATION_VIEW_H
#define OUTPUTNUMERICALRESULTNOTIFICATION_VIEW_H

#include "Common/etlbase.h"

class View;

class OutputNumericalResultNotification_view: public IPropertyNotification
{
public:
    std::string resultStr;

    OutputNumericalResultNotification_view(View *view): _view(view) {}
    void OnPropertyChanged(const std::string& str);
private:
    View *_view;
};

#endif // OUTPUTNUMERICALRESULTNOTIFICATION_VIEW_H
