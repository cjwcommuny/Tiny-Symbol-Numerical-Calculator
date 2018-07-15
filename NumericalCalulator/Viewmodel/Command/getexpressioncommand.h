#ifndef GETEXPRESSIONCOMMAND_H
#define GETEXPRESSIONCOMMAND_H
#include "lib/etlbase.h"
#include <memory>
#include "Viewmodel/Command/command.h"
#include "Viewmodel/viewmodel.h"

class Viewmodel;
class Command;

class getExpressionCommand: public Command
{
public:
    getExpressionCommand(Viewmodel *vm): viewmodel(vm) {}
    void Exec() override;
private:
    Viewmodel *viewmodel;

};

#endif // GETEXPRESSIONCOMMAND_H
