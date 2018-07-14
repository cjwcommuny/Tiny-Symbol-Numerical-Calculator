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
    QString _str;
public:
    StringParameter(QString str): _str(str) {}
    QString getString() {return _str;}
};

#endif // PARAMETER_H
