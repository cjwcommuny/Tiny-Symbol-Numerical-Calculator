#ifndef COMMAND_H
#define COMMAND_H

#include <memory>
#include "Viewmodel/viewmodel.h"
#include "Parameter/parameter.h"
#include "lib/etlbase.h"

class Command: public ICommandBase
{
public:
    Command();
    virtual void Exec() = 0;
    void SetParameter(std::shared_ptr<Parameter> param) {parameter = param;}
protected:
    std::shared_ptr<Parameter> parameter;
private:

};

#endif // COMMAND_H
