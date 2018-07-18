#ifndef GETEXPRESSIONCOMMAND_H
#define GETEXPRESSIONCOMMAND_H
#include "Common/etlbase.h"
#include <memory>
#include "Common/command.h"


class Viewmodel;

class getExpressionCommand: public Command
{
public:
    getExpressionCommand(Viewmodel *vm): viewmodel(vm) {}
    void Exec() override;
private:
    Viewmodel *viewmodel;

};

#endif // GETEXPRESSIONCOMMAND_H
