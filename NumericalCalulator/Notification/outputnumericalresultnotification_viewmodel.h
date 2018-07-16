#ifndef OUTPUTNUMERICALRESULTNOTIFICATION_VIEWMODEL_H
#define OUTPUTNUMERICALRESULTNOTIFICATION_VIEWMODEL_H
#include "Common/etlbase.h"

class Viewmodel;

class OutputNumericalResultNotification_viewmodel: public IPropertyNotification
{
public:
    OutputNumericalResultNotification_viewmodel(Viewmodel *viewmodel): _viewmodel(viewmodel) {}
    void OnPropertyChanged(const std::string& str);
private:
    Viewmodel *_viewmodel;
};

#endif // OUTPUTNUMERICALRESULTNOTIFICATION_VIEWMODEL_H
