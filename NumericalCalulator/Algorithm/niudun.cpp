#include"algorithm/niudun.h"
#include"Common/polynomial.h"
#include <assert.h>
double fun(double a)
{
    double sum = 0;
    Link *node = head;
    while(node != NULL)
    {
        sum += node->Num*pow(a,node->Index);
        node = node->Next;
    }
    return sum;
}
double cfun(double a)
{
    double sum = 0;
    Link *node=head;
    while(node->Index)
    {
        sum += node->Index * node->Num * pow(a,node->Index-1);
                node = node->Next;
    }
    return sum;
}
double niudun(const LinkList &ll)
{
    double n = ll.Get_max();
    Link *tail = ll.gethead();
    double Max1 =tail->Num>0?tail->Num:-tail->Num;
    double a = 0.0;
    while(!cfun(a))
        a+=1;
    double Max = pow(10000,1.0/n)>Max1?pow(10000,1.0/n):Max1;
    double Min = -Max;
    for(int i = 0;i<1000;i++)
    {
        if(cfun(a))
        {
        a = a - fun(a)/cfun(a);
        a = a>Max?Max:a<Min?Min:a;
        }
        if(pow(fun(a),2)<pow(0.01,2))
        {
            return a;
        }
    }
    cout<<"not find"<<endl;
}
