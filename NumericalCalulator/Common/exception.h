#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>


class BraceNoCompatibleException: public std::exception
{
public:
    BraceNoCompatibleException(): std::exception("Braces not compatible") {}
};

class IllegalCharacterException: public std::exception
{
public:
    IllegalCharacterException(): std::exception("Illegal Character") {}
};

class FunctionNotFoundException: public std::exception
{
public:
    FunctionNotFoundException(): std::exception("Function not found") {}
};

class SolutionNotFoundException: public std::exception
{
public:
    SolutionNotFoundException(): std::exception("Solution not found") {}
};


class UnexpectExpressionException: public std::exception //when the above exception not compatible, use this
{
public:
    UnexpectExpressionException(): std::exception("Unexpect expression") {}
};

class ProcessFailException: public std::exception // when algorithm fails, use this
{
public:
    ProcessFailException(): std::exception("Process failed") {}
};

class MatrixNotCompatibleException: public std::exception // when algorithm fails, use this
{
public:
    MatrixNotCompatibleException(): std::exception("Matrices not compatible") {}
};

class InversionFailedException: public std::exception // when inverse matrix does not exist, use this
{
public:
    InversionFailedException(): std::exception("Inverse matrix doesn't exist") {}
};

class MatrixRankNotFullException: public std::exception 
{
public:
    MatrixRankNotFullException(): std::exception("The rank of the matrix is not full") {}
};

class EquationNoSolutionException: public std::exception 
{
public:
    EquationNoSolutionException(): std::exception("The equation doesn't have solution") {}
};

class EquationSolutionIsRException: public std::exception 
{
public:
    EquationSolutionIsRException(): std::exception("The solution of this equation can be andy number in R") {}
};

#endif // EXCEPTION_H
