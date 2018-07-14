#ifndef GETEXPRESSIONCOMMAND_H
#define GETEXPRESSIONCOMMAND_H
#include "lib/etlbase.h"
#include <memory>
#include "Viewmodel/Command/command.h"

class getExpressionCommand: Command
{
public:
    getExpressionCommand(Viewmodel *vm): viewmodel(vm) {}
    void Exec();
private:
    Viewmodel *viewmodel;

};

#endif // GETEXPRESSIONCOMMAND_H
