#include <memory>
#include <vector>
#include "Model/model.h"
using namespace std;


Model::Model()
{
    expression = std::make_shared<std::string>("null string");
}

bool Model::transmit_expression(std::string str)
{
    //process the expression
    if (str == "error") {
        //notifyFailure();
        return false;
    } else {
        *expression = str;
        notifyResult();
        return true;
    }
}

void Model::notifyResult()
{
    Fire_OnPropertyChanged("ResultGenerated");
}


