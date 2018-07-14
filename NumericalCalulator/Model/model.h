#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include "lib/etlbase.h"

class Model: Proxy_PropertyNotification<>
{
public:
    Model();
    void notify();

    void transmit_expression(QString str);
private:
    QString expression;
};

#endif // MODEL_H
