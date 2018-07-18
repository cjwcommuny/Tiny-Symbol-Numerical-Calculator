#ifndef _POLYNOMINAL_H
#define _POLYNOMINAL_H
#include<iostream>
using namespace std;
#include<malloc.h>
#include<math.h>
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
    size_t MAX;
    Link *head,*tail;
    std::map<int,int> get_coefficient;
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
    int Get_coefficient(int i);
    void print();
};
#endif
