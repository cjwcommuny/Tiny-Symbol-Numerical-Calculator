#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "lib/etlbase.h"
//#include "Viewmodel/viewmodel.h"
#include "Parameter/parameter.h"


class Command: public ICommandBase
{
public:
    Command();
    virtual void Exec() = 0;
    void SetParameter(std::shared_ptr<Parameter> param) override {parameter = param;}
protected:
    std::shared_ptr<Parameter> parameter;
private:

};

#endif // COMMAND_H
