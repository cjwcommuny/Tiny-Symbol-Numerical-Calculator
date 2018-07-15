#include "model.h"

Model::Model()
{

}

void Model::transmit_expression(std::string str)
{
    //process the expression
    expression = str;
    notify();
}

void Model::notify()
{
    Fire_OnPropertyChanged("ResultGenerated");
}
