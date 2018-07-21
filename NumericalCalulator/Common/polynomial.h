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
    LinkList(string Equation);
    Link *gethead() const{return head;}
    Link *gettail() const{return tail;}
    Link * get();
    Link * Rank(Link *node);
    double Get_max() const
    {
        return MAX;
    }
    int analyze();
    double Get  (double i,char x) const;
    double compute(double x) const;
    void print() const
    {
        Link *current = head;
        while (current != nullptr) {
            std::cout << "coefficient: " << current->Num << "index: " << current->Index << std::endl;
            current = current->Next;
        }
    }
    std::string Quadrature();
};
#endif
