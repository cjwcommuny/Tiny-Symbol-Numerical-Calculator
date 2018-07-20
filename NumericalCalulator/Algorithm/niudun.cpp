<<<<<<< HEAD
#include"algorithm/niudun.h"
#include"Common/polynomial.h"
#include <assert.h>
double fun(double a, const LinkList &ll)
{
    double sum = 0;
    Link *node = ll.gethead();
=======
#include"common/polynomial.h"
double fun(double a)
{
    double sum = 0;
    Link *node = head;
>>>>>>> master
    while(node != NULL)
    {
        sum += node->Num*pow(a,node->Index);
        node = node->Next;
    }
    return sum;
}
<<<<<<< HEAD
double cfun(double a,const LinkList &ll)
{
    double sum = 0;
    Link *node=ll.gethead();
=======
double cfun(double a)
{
    double sum = 0;
    Link *node=head;
>>>>>>> master
    while(node->Index)
    {
        sum += node->Index * node->Num * pow(a,node->Index-1);
                node = node->Next;
    }
    return sum;
}
<<<<<<< HEAD
double niudun(const LinkList &ll)
{
    int n = ll.Get_max();
    Link *tail = ll.gethead();
    double Max1 =tail->Num>0?tail->Num:-tail->Num;
=======
double niudun(int n)
{
    int Max1 = tail->Num>0?tail->Num:-tail->Num;
>>>>>>> master
    double a = 0.0;
    double Max = pow(10000,1.0/n)>Max1?pow(10000,1.0/n):Max1;
    double Min = -Max;
    for(int i = 0;i<1000;i++)
    {
<<<<<<< HEAD
        if(cfun(a,ll))
        {
        a = a - fun(a,ll)/cfun(a,ll);
        }
        if(pow(fun(a,ll),2)<pow(0.01,2))
        {
            a = (int)(a*100+0.5)/100.0;
=======
        if(cfun(a))
        {
        a = a - fun(a)/cfun(a);
        }
        if(pow(fun(a),2)<pow(0.01,2))
        {
            cout<<a<<endl;
>>>>>>> master
            return a;
        }
    }
    cout<<"not find"<<endl;
}
