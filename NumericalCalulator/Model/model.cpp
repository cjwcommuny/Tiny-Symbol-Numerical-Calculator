#include "Model/model.h"
#include <memory>
#include "Algorithm/generalparser.h"
#include "Parameter/Parameter.h"


Model::Model()
{
    expression = std::make_shared<std::string>("null string");
    _vertexArr = std::make_shared<std::vector<Point>>(1);
}

bool Model::transmit_expression(std::string str)
{
    //process the expression
    std::cout << "=======model get parameter=======" << std::endl;
    std::shared_ptr<Parameter> resultParameter = generalParser(str);
    std::cout << "=======generate parameter=======" << std::endl;
    if (str == "error") {
        //notifyFailure();
        return false;
    } else {
        if (resultParameter->getParameterType() == stringParameter) {
            *expression = std::static_pointer_cast<StringParameter>(resultParameter)->getString();
            notifyResult();
        } else if (resultParameter->getParameterType() == vectorParameter) {
            std::cout << "=============parameter parser==========" << std::endl;
            *_vertexArr = std::static_pointer_cast<VectorParameter<Point>>(resultParameter)->getVector();
            notifyCurveResult();
        }
        //*expression = generalParser(str);
        return true;
    }
}

void Model::notifyCurveResult()
{
    Fire_OnPropertyChanged("CurveVertexGenerated");
}

void Model::notifyResult()
{
    Fire_OnPropertyChanged("ResultGenerated");
}

