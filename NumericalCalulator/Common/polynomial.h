#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include<iostream>
using namespace std;
#include<malloc.h>
#include<cmath>
#include<map>
#include<string>
double fun(double a);
double cfun(double a);
double niudun(int n);
typedef struct link
{
    char X;
    double Num;
	struct link *Next;
    char Operator;
	int Index;
}Link;
static Link *head,*tail;
class LinkList
{
    std::string equation;
    private:
    size_t MAX;
    std::map<int,double> get_coefficient;
public:
	Link *head,*tail;
	public:
	LinkList();
	LinkList(string Equation);
    Link * get();
    Link * Rank(Link *head,Link *node);
    int Get_max()
    {
        return MAX;
    }
    int analyze();
    int Get(int i,char x,Link *head);
    double Get_coefficient(int i);
    double compute(double x) const;
    void print();
};
#endif
