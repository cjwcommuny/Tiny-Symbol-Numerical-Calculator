#include "model.h"

Model::Model()
{
    AddPropertyNotification(_viewmodel->notification);
}

void Model::transmit_expression(QString str)
{
    //process the expression
    expression = str;
    notify();
}

void Model::notify()
{
    Fire_OnPropertyChanged("ResultGenerated");
}
