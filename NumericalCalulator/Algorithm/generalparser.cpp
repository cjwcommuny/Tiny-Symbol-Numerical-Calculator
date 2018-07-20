#include "generalparser.h"
#include "Algorithm/matrixtransformation.h"
#include "Common/polynomial.h"
#include "Common/point.h"
#include "generatevertexarr.h"
#include "Common/polynomial.h"
#include "Algorithm/niudun.h"
#include <iostream>

std::shared_ptr<Parameter> generalParser(std::string expression)
{
    std::string resultStr;
    expression = removeSpace(expression);
    expression = removeComment(expression);
    //std::cout << "=============remove space end==========" << std::endl;
    std::vector<std::string> component_out;
    FunctionType functionName = seperateComponent(expression, component_out);
    std::cout << "=============seperate expression end==========" << std::endl;
    if (functionName == MatrixBinaryOperation) {
        std::shared_ptr<matrix> left_mat = std::make_shared<matrix>(matrix());
        std::shared_ptr<matrix> right_mat = std::make_shared<matrix>(matrix());
        //matrix left_mat, right_mat;
        char matrixOperator = simpleExpressionParser(expression, left_mat, right_mat);
        if (matrixOperator == '*') {
            resultStr = (*left_mat * *right_mat).toString();
        } else if (matrixOperator == '+') {
            resultStr = (*left_mat + *right_mat).toString();
        } else if (matrixOperator == '-') {
            resultStr = (*left_mat - *right_mat).toString();
        }
        return std::make_shared<StringParameter>(StringParameter(resultStr));
    } else if (functionName == MatrixInversion) {
        std::shared_ptr<matrix> mat = matrixParser(component_out[0]);
        std::shared_ptr<matrix> mat2 = matrixInverse(*mat);
        resultStr = mat2->toString();
        return std::make_shared<StringParameter>(StringParameter(resultStr));
    } else if (functionName == ComputeDeterminant) {
        //std::cout << "=============ComputeDeterminant test==========" << std::endl;
        std::shared_ptr<matrix> mat = matrixParser(component_out[0]);
        //std::cout << "=============matrix parser end==========" << std::endl;
        double result = computeDeterminant(*mat);
        std::stringstream ss;
        ss << result;
        resultStr = ss.str();
        return std::make_shared<StringParameter>(StringParameter(resultStr));
    } else if (functionName == MatrixTranspose) {
        std::shared_ptr<matrix> mat = matrixParser(component_out[0]);
        std::shared_ptr<matrix> mat2 = matrixTranspose(*mat);
        resultStr = mat2->toString();
        return std::make_shared<StringParameter>(StringParameter(resultStr));
    } else if (functionName == SolvePolynomialEquation) {
        std::cout << "==========start solvepoly=========" << std::endl;
        LinkList polynomial(component_out[0]);
        std::cout << "==========poly parser end =========" << std::endl;
        std::cout << "polynomial: " << component_out[0] << std::endl;
        double resultDouble = niudun(polynomial);
        std::cout << "==========newton method end=========" << std::endl;
        std::stringstream ss;
        ss << resultDouble;
        std::cout << "sss.str: " << ss.str() << std::endl;
        return std::make_shared<StringParameter>(ss.str());
    } else if (functionName == DrawPolynomialCurve) {
        //std::cout << "=============polynomial test==========" << std::endl;
        LinkList polynomial(component_out[0]);
        //std::cout << "==========polynomial: ============" << std::endl;
        //polynomial.print();
        //std::cout << "==========polynomial end==========" << std::endl;
        std::vector<Point> vertexArr = generateVertexArr(polynomial);
        //std::cout << "=========== vector test start=========" << std::endl;
        //for (auto iter = vertexArr.cbegin(); iter != vertexArr.cend(); ++iter) {
           // std::cout << "X: " << iter->getX() << " Y: " << iter->getY() << std::endl;
        //}
        //std::cout << "=========== vector test end=========" << std::endl;
        return std::make_shared<VectorParameter<Point>>(VectorParameter<Point>(vertexArr));
    }
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

std::string removeComment(std::string expression)
{
    auto iter = expression.cbegin();
    for (; iter != expression.cend(); ++iter) {
        if (*iter == '#') {
            break;
        }
    }
    std::string result(expression.cbegin(), iter);
    return result;
}

FunctionType seperateComponent(const std::string &expression, std::vector<std::string> &component_out)
{
    if (*(expression.cbegin()) == '[') {//binary matrix operation
        return MatrixBinaryOperation;
    }
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
                throw UnexpectExpressionException();
            }
        }
    }
    if (leftBraceFound == false || rightBraceFound == false) {
        throw BraceNoCompatibleException();
    } else if (leftBracePosition > rightBracePosition) {
        throw BraceNoCompatibleException();
    }
    std::string functionName(expression.cbegin(), leftBracePosition);
    if (functionName == "draw")
    {
        std::string subExpression(leftBracePosition + 1, rightBracePosition);
        component_out.push_back(subExpression);
        return DrawPolynomialCurve;
    }
    else if (functionName == "SolveLinear")
    {
        //TODO
    }
    else
    { //single parameter
        std::string subExpression(leftBracePosition + 1, rightBracePosition);
        component_out.push_back(subExpression);
        if (functionName == "ComputeDeterminant")
        {
            return ComputeDeterminant;
        }
        else if (functionName == "SolvePoly")
        {
            std::cout << "==========recognize solvepoly=========" << std::endl;
            return SolvePolynomialEquation;
        }
        else if (functionName == "invert")
        {
            return MatrixInversion;
        }
        else if (functionName == "transpose")
        {
            return MatrixTranspose;
        }
        else
        { //no such functionName
            throw FunctionNotFoundException();
        }
    }
}
