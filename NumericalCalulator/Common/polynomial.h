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
    Link * get();
    Link * Rank(Link *node);
    double Get_max() const
    {
        return MAX;
    }
    int analyze();
    Link *gethead() const {return head;}
    Link *gettail() const {return tail;}
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
    double getCoefficient(double index) const 
    {
        const double epsilon = 0.001;
        Link *current = head;
        while (current != nullptr) {
            //std::cout << "coefficient: " << current->Num << "index: " << current->Index << std::endl;
            if (fabs(current->Index - index) < epsilon) {
                return current->Num;
            }
            current = current->Next;
        }
    }
};
#endif
