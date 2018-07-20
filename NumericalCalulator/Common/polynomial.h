#ifndef _POLYNOMINAL_H
#define _POLYNOMINAL_H
#include<iostream>
using namespace std;
#include<malloc.h>
#include<math.h>
#include<map>
#include<string>
#include<sstream>
typedef struct link
{
    char X;
    double Num;
    struct link *Next;
    double Index;
}Link;
class LinkList
{
    std::string equation;
    private:
    Link *head,*tail;
    size_t MAX;
    std::map<double,double> get_coefficient;
    public:
    LinkList();
    LinkList(string Equation);
    Link * get();
    Link * Rank(Link *node);
    double Get_max() const
    {
        return MAX;
    }
    int analyze();
    string Quadrature();
    double Get(double i,char x) const;
    double Get_coefficient(double i) ;
    //void print();
    double compute(double x) const;
};
#endif
