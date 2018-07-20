#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include<iostream>
using namespace std;
#include<malloc.h>
#include<cmath>
#include<map>
#include<string>
<<<<<<< HEAD
#include<sstream>
=======
double fun(double a);
double cfun(double a);
double niudun(int n);
>>>>>>> master
typedef struct link
{
    char X;
    double Num;
<<<<<<< HEAD
    struct link *Next;
    double Index;
=======
	struct link *Next;
    char Operator;
	int Index;
>>>>>>> master
}Link;

 class LinkList
{
    std::string equation;
    private:
    Link *head,*tail;
    size_t MAX;
<<<<<<< HEAD
    map<int,int> get_coefficient;
    public:
    LinkList();
    Link* gethead() const {return head;}
    Link* gettail() const {return tail;}
    LinkList(string Equation);
    Link * get  ();
    Link * Rank (Link *head,Link *node);
    int Get_max () const
=======
    std::map<int,double> get_coefficient;
public:
	Link *head,*tail;
	public:
	LinkList();
	LinkList(string Equation);
    Link * get();
    Link * Rank(Link *head,Link *node);
    int Get_max()
>>>>>>> master
    {
        return MAX;
    }
    int analyze();
<<<<<<< HEAD
    double Get  (int i,char x,Link *head) const;
=======
    int Get(int i,char x,Link *head);
>>>>>>> master
    double Get_coefficient(int i);
    double compute(double x) const;
    void print();
    string Quadrature();
};
#endif
