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
	int Num;
	struct link *Next;
	char Operator;
	int Index;
}Link;

class LinkList
{
    std::string equation;
	private:
    size_t MAX;
    std::map<int,int> get_coefficient;
	Link *head,*tail;
	public:
	LinkList();
	LinkList(string Equation);
        Link * get();
        int Get_max()
        {
            return MAX;
        }
        int analyze(); 
        int Get(int i,char x,Link *head);
        int Get_coefficient(int i);
        //void prit(Link *head); 
		};
#endif
