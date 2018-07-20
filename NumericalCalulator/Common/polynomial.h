#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include<iostream>
using namespace std;
#include<malloc.h>
#include<cmath>
#include<map>
#include<string>
typedef struct link
{
    char X;
    double Num;
	struct link *Next;
    char Operator;
	int Index;
}Link;

 class LinkList
{
    std::string equation;
    private:
    Link *head,*tail;
    size_t MAX;
    map<int,int> get_coefficient;
    public:
    LinkList();
    Link* gethead() const {return head;}
    Link* gettail() const {return tail;}
    LinkList(string Equation);
    Link * get  ();
    Link * Rank (Link *head,Link *node);
    int Get_max () const
    {
        return MAX;
    }
    int analyze();
    int Get  (int i,char x,Link *head) const;
    int Get_coefficient(int i);
    double compute(double x) const;
    //void print();
};
#endif
