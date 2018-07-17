#include "Model/model.h"


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
        /*
        std::shared_ptr<matrix> mat =  matrixParser(str);
        double result_determinant = ComputeDeterminant(*mat);
        std::stringstream ss;
        ss << result_determinant;
        *expression = ss.str();
        * */
        *expression = str;
        notifyResult();
        return true;
    }
}

void Model::notifyResult()
{
    Fire_OnPropertyChanged("ResultGenerated");
}

