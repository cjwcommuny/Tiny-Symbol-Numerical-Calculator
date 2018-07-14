#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include "lib/etlbase.h"
#include "Notification/notification.h"
#include "Viewmodel/viewmodel.h"

class Model: Proxy_PropertyNotification<Model>
{
public:
    Model();
    void notify();

    void transmit_expression(QString str);
    void bind(std::shared_ptr<Viewmodel> viewmodel) {_viewmodel = viewmodel;}
private:
    QString expression;
    std::shared_ptr<Viewmodel> _viewmodel;
};

#endif // MODEL_H
