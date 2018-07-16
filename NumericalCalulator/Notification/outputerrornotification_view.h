#ifndef OUTPUTERRORNOTIFICATION_VIEW_H
#define OUTPUTERRORNOTIFICATION_VIEW_H

#include "Common/etlbase.h"
class View;

class OutputErrorNotification_view: public ICommandNotification
{
public:
    OutputErrorNotification_view(View *view): _view(view) {}
    void OnCommandComplete(const std::string& str, bool bOK);
private:
    View *_view;
};

#endif // OUTPUTERRORNOTIFICATION_VIEW_H
