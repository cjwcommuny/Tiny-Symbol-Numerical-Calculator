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

class MatrixRankNotFullException: public std::exception // when algorithm fails, use this
{
public:
    MatrixRankNotFullException(): std::exception("The rank of the matrix is not full") {}
};

#endif // EXCEPTION_H
