#ifndef PARAMETER_H
#define PARAMETER_H


class Parameter
{
public:
    Parameter();
};

class StringParameter: public Parameter
{
private:
    std::string _str;
public:
    StringParameter(std::string str): _str(str) {}
    std::string getString() {return _str;}
};

#endif // PARAMETER_H
