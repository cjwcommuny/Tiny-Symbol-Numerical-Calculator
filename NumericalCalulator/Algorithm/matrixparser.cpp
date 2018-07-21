#include "Algorithm/matrixparser.h"
#include "Common/exception.h"
using namespace std;

char simpleExpressionParser(std::string expression, shared_ptr<matrix> &M1, shared_ptr<matrix> &M2)
{
    int l = expression.length();
    int i = 0, l1 = 0;
    char ope;
    while((expression[l1] != '+' && expression[l1] != '-' && expression[l1] != '*') && l1 < l)
            l1++;
    ope = expression[l1];
    string temp;
    temp.assign(expression, i, l1 - i);
    cout<<"temp = "<<temp<<endl;
    M1 = matrixParser(temp);
    i = ++l1;
    //while(expression[] != '[' && i < l)
     //   i++;
    temp.assign(expression, i, l - i + 1);
    cout<<"temp = "<<temp<<endl;
    M2 = matrixParser(temp);
    return ope;
}

/*this function is used to analyse an expression with only one pair of '[' and ']', and return a pointer to a matrix */
std::shared_ptr<matrix> SingleRowmatrixParser(std::string expression)
{
    //cout<<expression<<endl;
    shared_ptr<matrix> mptr(new matrix);
    vector<double> tVec;
    double tUncertain;
    int rc = 1; //rc = 1 means it is a single-row matrix, while rc = 0 means it is a single-column matrix
    int l = expression.length();
    int i = 1;
    int l1 = 0;
    int count = 0, c = 0;  //variable 'count' stores the amount of numbers, while 'c' stores the amount of semicolons
    while (i < l)
    {
        l1 = i;        //begin location of the number
        if (expression[l1] == '[')
        {
            throw BraceNoCompatibleException();
        }
        while((expression[l1] >= '0' && expression[l1]<= '9' )|| expression[l1] == '-' || expression[l1] == '.')
            l1++;      //end location of the number

        string temp;	//transfer the string to T type
        temp.assign(expression, i, l1 - i + 1);

        //temp.assign(expression, i, l1 - i);
        stringstream stream(temp);
        stream >> tUncertain;
        cout<<"tUncertain = "<<tUncertain<<endl;

        tVec.push_back(tUncertain);
        count++;
        i = l1;

        while (expression[i] == ' ' || expression[i] == ',')
            i++;  //skip the blanks
        if (expression[i] == ';')
        {
            rc = 0;
            i++;
            c++;
        }
        while (expression[i] == ' ' || expression[i] == ',')
            i++;  //skip the blanks    
        if (rc == 0)
        {
            mptr->setData(tVec);
            tVec.clear();
        }
        if(expression[i] == ']')
            break;
    }

    cout<<"count= "<<count<<"  and c = "<<c<<endl;
    if (rc == 1)
    {
        mptr->setRow(1);
        mptr->setCol(count);
        mptr->setData(tVec);
    }
    else if (rc == 0)
    {
        if (count - c != 1)  //if the columns are not all the same
        {
            //throw MatrixNotCompatibleException();
            cout << "error: vertical matrix dismatch" << endl;
        }
        mptr->setCol(1);
        mptr->setRow(count);
        //cout << "size = " << sizeof(tVec) / sizeof(tVec[0]) - 1 << endl;
    }
    return mptr;
}

/*this function is used to analyse an expression with many pairs of '[' and ']', and return a pointer to a matrix */
std::shared_ptr<matrix> matrixParser(std::string expression)
{
    shared_ptr<matrix> mptr(new matrix);
    mptr->setRow(0);
    mptr->setCol(0);
    vector<double> tVec;
    double tUncertain;
    int l = expression.length();
    int i = 0;
    int l1 = 0;
    int l2 = 0;
    int count = 0, j;
    int count1 = 0, count2 = 0;
    string temp;
    for (int s = 0; s < l; s++)
    {
        if ((expression[s] < '0' || expression[s] > '9') && expression[s] != ' ' &&expression[s] != ',' &&expression[s] != ';' && expression[s] != '[' && expression[s] != ']'&& expression[s] != '-' &&expression[s] != '.')
        {
            throw IllegalCharacterException();
            cout << "syntax error at location: " << s << endl;
            return mptr;
        }
        if(expression[s] == '[') count1++;
        if(expression[s] == ']') count2++;
    }
    if(count1 != count2)
        throw BraceNoCompatibleException();
    while(expression[i] == ' ') i++;
    if (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '-' || expression[i] == '.')
    {
        temp.assign(expression, i, l - i + 1);
        stringstream stream(temp);
        stream >> tUncertain;
        size_t u = l - 1;
        while(expression[u] == ' ')
            u--;
        if(expression[u] == ']')
            throw BraceNoCompatibleException();

        //set the parameters of the matrix
        mptr->setRow(1);
        mptr->setCol(1);
        tVec.push_back(tUncertain);
        mptr->setData(tVec);
        return mptr;
    }
    else if (expression[i++] == '[')    // [1; 2; 3]
    {
        //while (expression[i] == ' ') i++;
        if (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '-')
        {
            int t = l -1;
            while(expression[t] == ' ' || expression[t] == ';')
                t--;     //l - 1 - (i - 1)+ 1
            //temp.assign(expression, i - 1, l - i + 2);
            temp.assign(expression, i - 1, t - i + 1);
            if (expression[t] != ']')
            {
                throw BraceNoCompatibleException();
                //cout << "error: there is no corresponding ']'" << endl;
            }
            mptr = SingleRowmatrixParser(temp);
            return mptr;

        }

        else if (expression[i] == '[')  //[[003, 04 5], 2 ,3, 4] [7, 7 ,7] [2 5 8]
        {
            shared_ptr<matrix> mt(new matrix);
            int flag = 0;
            int rc = 1;  // ' 'or ','for seperation
            int countMatrix = 0, cMatrix = 0;
            while (i < l)
            {
                l2 = i;
                while (expression[l2] != ']' && l2 <= l - 1)
                {
                    l2++;
                }

                temp.assign(expression, i, l2 - i + 1);
                cout<<"temp = "<<temp<<endl;
                mt = SingleRowmatrixParser(temp);
                mt->print();
                if (mt->getCol() == 0 && mt->getRow() == 0)
                    return mt;
                countMatrix++;
                l2++;

                if (expression[l2] == '\0')    //no ']' in the end of the expression
                {
                    throw BraceNoCompatibleException();
                    //cout << "error: nooooooo corresponding ']' in the end" << endl;
                }

                if (expression[l2] == ']')  //end of the expression
                {
                    //rc = 1;
                    l2++;
                    cMatrix++;
                    flag = 1;
                    while(expression[l2] == ' ' && l2 <= l - 1)
                    {
                        l2++;
                        if(expression[l2] == ']')
                        {
                            throw BraceNoCompatibleException();
                            //cout << "error: dismatch of '[' and ']' " << endl;
                        }
                    }
                }
                else
                {
                    while (expression[l2] != '[' && l2 < l - 1)
                    {
                        if (expression[l2] == ';')
                        {
                            rc = 0;   //';' for seperation
                            cMatrix++;
                        }
                        if (expression[l2] >= '0' && expression[l2] <= '9')
                        {
                            throw BraceNoCompatibleException();
                            //cout << "error: lack of '['" << endl;
                        }
                        l2++;
                    }
                }

                if (rc == 0 && mt->getRow() == 1)  //单行合并列
                {
                    mptr->setRow(mptr->getRow() + 1);      //add one row to the matrix
                    mptr->setCol(mt->getCol());
                    for (j = 0; j < mt->getCol(); j++)
                    {
                        tVec.push_back(mt->getData(0, j));
                        //cout << mt->getData(0, j) << "  " << endl;
                    }
                    mptr->setData(tVec);
                    i = l2;
                    tVec.clear();
                }

                else if (rc == 1 && mt->getRow() == 1)  //单行合并行
                {
                    mptr->setCol(mptr->getCol() + mt->getCol());
                    for (j = 0; j < mt->getCol(); j++)
                    {
                        tVec.push_back(mt->getData(0, j));
                        //cout << mt->getData(0, j) << "  " << endl;
                    }
                    i = l2;
                }

                else if (rc == 0 && mt->getCol() == 1)   //单列合并列
                {
                    mptr->setRow(mptr->getRow() + mt->getRow());
                    for (j = 0; j < mt->getRow(); j++)
                    {
                        tVec.push_back(mt->getData(j, 0));
                        mptr->setData(tVec);
                        tVec.clear();
                    }
                    i = l2;
                }

                else if (rc == 1 && mt->getCol() == 1)   //单列合并行
                {
                    mptr->setCol(mptr->getCol() + 1);
                    mptr->setRow(mt->getRow());
                    for (j = 0; j < mt->getRow(); j++)
                    {
                        tVec.push_back(mt->getData(j, 0));
                    }
                    i = l2;
                }
            }
            cout << "cMatrix: " << cMatrix << endl;
            cout << "countMatrix: " << countMatrix << endl;
            if (cMatrix != 1 && countMatrix - cMatrix != 0)
            {
                throw MatrixNotCompatibleException();
                //cout << "dismatch of matrixes" << endl;
            }
            if (rc == 0 && mt->getRow() == 1)
            {

            }
            if (rc == 1 && mt->getRow() == 1)
            {
                mptr->setRow(1);
                mptr->setData(tVec);
            }
            if (rc == 0 && mt->getCol() == 1)
            {
                mptr->setCol(1);
            }
            if (rc == 1 && mt->getCol() == 1)
            {
                vector <double> tem;
                for (int v = 0; v < mptr->getRow(); v++)
                {
                    for (int u = 0; u < mptr->getCol(); u++)
                    {
                        tem.push_back(tVec[v + mptr->getRow()*u]);
                    }
                    mptr->setData(tem);
                    tem.clear();
                }

            }

            return mptr;
        }
    }
    else
    {
        cout << "Wrong input" << endl;
        mptr->setRow(0);
        mptr->setCol(0);
    }
    return mptr;
}


