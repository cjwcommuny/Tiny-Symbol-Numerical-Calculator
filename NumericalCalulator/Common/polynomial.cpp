#include "Common/polynomial.h"
#include <sstream>

double LinkList::compute(double x) const
{
    Link *current = head;
    double result = 0;
    while (current != nullptr) {
        result += current->Num * pow(x, current->Index);
        current = current->Next;
    }
    return result;
}
LinkList::LinkList(string Equation)
{
    MAX = 0;
    for(int i =0;i<Equation.length();i++)
    {
        if(Equation[i] != ' ')
        equation+=Equation[i];
    }
    head = tail = (Link*)malloc(sizeof(Link));
    head =tail = NULL;
    try{
        if(this->analyze()==1)
        throw "abc";
        this->get();
        this->print();
    }
    catch(char *)
    {
        cout<<"incrroct input"<<endl;
    }
}
int LinkList::analyze()
{
    int t=-1,equal=0;
    size_t size;
    size = equation.length();
    for(int j=0;j<size;j++)
    {
        if(t==-1&&((equation[j]>='a'&&equation[j]<='z')||(equation[j]>='A'&&equation[j]<='Z')))
        t=j;
    }
    for(int M=0;M<size;M++)
     {
        if(!((equation[M]>='0'&&equation[M]<='9')||equation[M]=='.'||equation[M]==equation[t]||equation[M]=='+'||equation[M]=='-'||equation[M]=='='||equation[M]=='^'))
        return 1;
     }
     for(int M=0;M<size;M++)
     {
        if(equation[M]=='=')
        equal++;
     }
     if(equal>1) return 1;
    if((equation[0]>'0'&&equation[0]<='9')||equation[0]=='-'||equation[0]==equation[t])
    if((equation[size-1]>='0'&&equation[size-1]<='9')||equation[size-1]==equation[t])
    {
        for(int i = 0;i<size-1;i++)
    {
        if(equation[i]>='0'&&equation[i]<='9')
        {
             if(!(equation[i+1]>='0'&&equation[i+1]<='9'||equation[i+1]=='.'||equation[i+1]==equation[t]||equation[i+1]=='='||equation[i+1]=='+'||equation[i+1]=='-'))
             return 1;
        }
         else if(equation[i]=='^')
        {
             if(!(equation[i+1]>='0'&&equation[i+1]<='9'))
             return 1;
         }
         else if(equation[i]=='+'||equation[i]=='-')
         {
             if(!((equation[i+1]>'0'&&equation[i+1]<='9')||equation[i+1]==equation[t]||'('))
             return 1;
         }
         else if(equation[i]==equation[t])
         {
            if(!(equation[i+1]=='^'||equation[i+1]=='+'||equation[i+1]=='-'||equation[i+1]=='='))
            return 1;
         }
         else if(equation[i]=='=')
         {
            if(!(equation[i+1]==equation[t]||equation[i+1]=='-'||(equation[i+1]>='0'&&equation[i+1]<='9')))
            return 1;
         }
         else if(equation[i]=='.')
         {
            if(!(equation[i+1]>='0'&&equation[i+1]<='9'))
            return 1;
         }

    }
    return 0;
    }
    else
    return 1;
}
double LinkList::Get(double i,char x) const
{
    Link *node;
    node = head;
    while(node)
    {
        if(node->Index ==i&&node->X==x)
        return node->Num;
        node=node->Next;
    }
    return 0;
}

Link * LinkList::get(){
    int multiple,j = 0,k =1 ,Operator = 1;
    double m = 0;
    for(int i = 0; i < equation.length(); i ++)
    {
        multiple = 0;
            Link *newLinkList;
            newLinkList = (Link*)malloc(sizeof(Link));
            newLinkList->Next = NULL;
            if(equation[i] =='-'){i++;k=-1;}
            while(equation[i]<='9'&&equation[i]>='0'||equation[i]=='.'){
            if(equation[i]=='.') multiple = i;
            i++;j++;
            }
            if(j==0) newLinkList->Num = 1*Operator*k;
            else
            {
            while(j>0){
            if((i-j)>multiple)
             {
                m+=(equation[i-j]-48)*pow(10,j-1);j--;
             }
            else if((i-j)<multiple){m+=(equation[i-j]-48)*pow(10,j-2);j--;}
            else j--;
            }
            if(multiple!=0)
            m = m*(pow(10,multiple+1-i)*1.0);
            if(!m) m = 0;
            newLinkList->Num = m * k *Operator;
            m = 0;multiple = 0;
            }
            if((equation[i]>='a'&&equation[i]<='z')||(equation[i]>='A'&&equation[i]<='Z'))
            {
                newLinkList->X = equation[i];
                i++;
                if(equation[i]=='^')
                 {
                    i++;
                    while(equation[i]<='9'&&equation[i]>='0'||equation[i]=='.')
                     {
                        if(equation[i]=='.') multiple = i;
                        i++;j++;
                     }
                     while(j>0)
                      {
                        if((i-j)>multiple)
                        {
                            m+=(equation[i-j]-48)*pow(10,j-1);j--;
                          }
                          else if((i-j)<multiple){m+=(equation[i-j]-48)*pow(10,j-2);j--;}
                          else j--;
                        }
                        if(multiple!=0)
                        m = m*(pow(10,multiple+1-i)*1.0);
                        newLinkList->Index = m;
                        m = 0;
                 }
                 else newLinkList->Index = 1;
            }
            else{newLinkList->X = 0;newLinkList->Index=0;}
            if(equation[i]=='-')k = -1;
            if(equation[i]=='+')k = 1;
            else if(equation[i]=='=')
            {
                Operator = -Operator;
                if(equation[i+1]=='-'){k=-1;i++;}
                else k = 1;
            }
            MAX =( MAX>newLinkList->Index) ? MAX:newLinkList->Index;
            get_coefficient[newLinkList->Index]=newLinkList->Num;
            head = Rank(newLinkList);
    }
            return head;
}
Link * LinkList::Rank(Link *node)
{
    Link * temp = head;
    if(head == NULL)
    {
        head =tail = node;
    }
    else{
        if(node->Index>temp->Index)
        {
            node->Next = head;
            head = node;
        }
        else
        {
           while(temp->Next!=NULL)
            {
               if(node->Index<temp->Index&&node->Index>temp->Next->Index)
               {
                   node->Next=temp->Next;
                   temp->Next=node;
                   break;
               }
               temp=temp->Next;
            }
            if(temp->Next == NULL)
            {
                tail->Next = node;
                tail = node;
            }
        }
    }
    return head;
}
string LinkList::Quadrature()
{
    string x;
    std::stringstream t;
    Link *node = head;
    while(node)
    {
        if(node!=head&&node->Num>0)
        x += '+';
        t << (int)(node->Num/(node->Index+1.0)*100)/100.0;
        if(t.str()!="1")
        x +=t.str();
        t.str("");
        x += head->X;
        if(node->Index)
        {
            x +='^';
            t << node->Index + 1;
            x += t.str();
            t.str("");
        }

        node = node->Next;
    }
    x +="+C";
    return x;
}
