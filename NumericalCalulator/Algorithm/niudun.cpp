#include"common/polynomial.h"
#include"algorithm/niudun.h"
#include"Common/polynomial.h"
#include <assert.h>
double fun(double a, const LinkList &ll)
{
    double sum = 0;
    Link *node = ll.gethead();
    while(node != NULL)
    {
        sum += node->Num*pow(a,node->Index);
        node = node->Next;
    }
    return sum;
}
double cfun(double a,const LinkList &ll)
{
    double sum = 0;
    Link *node=ll.gethead();
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
    if(!cfun(a,ll))
        a++;
    double Max = pow(10000,1.0/n)>Max1?pow(10000,1.0/n):Max1;
    double Min = -Max;
    for(int i = 0;i<1000;i++)
    {
        if(cfun(a,ll))
        {
        a = a - fun(a,ll)/cfun(a,ll);
        }
        if(pow(fun(a,ll),2)<pow(0.01,2))
        {
            a = (int)(a*100+0.5)/100.0;
            return a;
        }
    }
    cout<<"not find"<<endl;
}
