#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>
#include <vector>

typedef enum
{
    stringParameter,
    vectorParameter
} ParameterType;

class Parameter
{
private:
  ParameterType _parameterType;
public:
  Parameter(ParameterType pt): _parameterType(pt) {}
    ParameterType getParameterType() const { return _parameterType; }
};

class StringParameter: public Parameter
{
private:
    std::string _str;
public:
    StringParameter(std::string str): _str(str), Parameter(stringParameter) {}
    std::string getString() const {return _str;}
    operator std::string() {return _str;}
};

template <typename T>
class VectorParameter: public Parameter
{
private:
    std::vector<T> _vec;
public:
    VectorParameter(std::vector<T> vec): _vec(vec), Parameter(vectorParameter) {}
    std::vector<T> getVector() const { return _vec; }
    operator std::vector<T>() { return _vec; }
};

#endif // PARAMETER_H
