#include "generalparser.h"

std::string generalParser(std::string expression)
{
    std::string resultStr;
    expression = removeSpace(expression);
    //std::cout << "=============remove space end==========" << std::endl;
    std::vector<std::string> component_out;
    FunctionType functionName = seperateComponent(expression, component_out);
    //std::cout << "=============seperate expression end==========" << std::endl;
    if (functionName == MatrixInversion) {
        std::shared_ptr<matrix> mat = matrixParser(component_out[0]);

    } else if (functionName == ComputeDeterminant) {
        //std::cout << "=============ComputeDeterminant test==========" << std::endl;
        std::shared_ptr<matrix> mat = matrixParser(component_out[0]);
        //std::cout << "=============matrix parser end==========" << std::endl;
        double result = computeDeterminant(*mat);
        std::stringstream ss;
        ss << result;
        resultStr = ss.str();
    } else if (functionName == SolvePolynomialEquation) {
        
    } else if (functionName == DrawPolynomialCurve) {

    }
    return resultStr;
}

std::string removeSpace(std::string expression)
{
    std::string result;
    for (auto iter = expression.cbegin(); iter != expression.cend(); ++iter) {
        if (*iter != ' ' && *iter != '\t' && *iter != '\n') {//character not space
            result.push_back(*iter);
        }
    }
    return result;
}

FunctionType seperateComponent(const std::string &expression, std::vector<std::string> &component_out)
{
    auto leftBracePosition = expression.cbegin();
    auto rightBracePosition = expression.cbegin();
    bool leftBraceFound = false, rightBraceFound = false;
    for (auto iter = expression.cbegin(); iter != expression.cend(); ++iter) {
        if (leftBraceFound == false && *iter == '(') {
            leftBracePosition = iter;
            leftBraceFound = true;
        } else if (rightBraceFound == false && *iter == ')') {
            rightBracePosition = iter;
            rightBraceFound = true;
            if (rightBracePosition != expression.cend() - 1) {
                //error: redundant symbol in the tail of expression
            }
        }
    }
    if (leftBraceFound == false || rightBraceFound == false) {
        //error: brace not found or not compatible
    } else if (leftBracePosition > rightBracePosition) {
        //error: brace not compatible
    }
    std::string functionName(expression.cbegin(), leftBracePosition);
    if (functionName == "Draw") {
        
    } else {//single parameter
        std::string subExpression(leftBracePosition + 1, rightBracePosition);
        component_out.push_back(subExpression);
        if (functionName == "ComputeDeterminant") {
            return ComputeDeterminant;
        } else if (functionName == "SolvePoly") {
            return SolvePolynomialEquation;
        } else if (functionName == "invert") {

        } else if (functionName == "transpose") {

        }
        else {//no such functionName
            //error: no such function name
        }
    }
}
