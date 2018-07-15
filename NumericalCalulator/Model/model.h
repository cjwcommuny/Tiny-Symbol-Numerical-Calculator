#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include "lib/etlbase.h"
#include "Notification/notification.h"
#include "Notification/outputnumericalresultnotification_viewmodel.h"
#include "Viewmodel/viewmodel.h"
#include "Common/matrix.h"

class Viewmodel;
class Matrix;

class Model: public Proxy_PropertyNotification<Model>
{
public:
    Model();
    void notify();
    void transmit_expression(std::string str);
    std::shared_ptr<std::string> getExpression() {return expression;}
private:
    std::shared_ptr<std::string> expression;
    std::shared_ptr<Matrix> matrixParser(std::string expression);
};

#endif // MODEL_H
