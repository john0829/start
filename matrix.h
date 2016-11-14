#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <list>
#include "vector.h"
using namespace std;

class matrix {
public:
    matrix(int a, Vector vs[])
    :n(a),v(new Vector[a]){
        for (int i=0; i<n; ++i)
            v[i] = vs[i];
    }
    int n_vertices() const {return n;}
    Vector & vertex(int i) const {
        return v[i-1];}

    void reduce ()
    {
        double twonum;
        double firstnum;
        int dependent=0;
        int c=0;
        for(int cont=0;cont<=n-2;++cont)
        {
            c=cont;//cont=reducetime
            if(cont<n-1)
                dependent = searchnonzero(n,cont);

            if(dependent==1)
            {
                c++;
                dependent = searchnonzero(n,cont);
            }
            //find  row first num is not zero ,if all zero=wrong
            firstnum=v[cont].component(c+1);//equal
            for (int i=cont+1; i<=n-1; ++i)
            {
                //minus
                twonum=v[i].component(c+1);
                double number=twonum/firstnum;
                number=twonum/firstnum;
                v[i]=v[i]-v[cont]*number;
                print();
            }
        }
        cout<<"finishfinish"<<endl;
        becomeone();
}


    int searchnonzero(int n,int reducetime){
        double * const replacement = new double[100];
        Vector replaceee(100,replacement);
        int counter2=reducetime+1;
        int wrong=0;
        while(v[reducetime].component(reducetime+1)==0)
        {
            replaceee=v[reducetime];
            v[reducetime]=v[counter2];
            v[counter2]=replaceee;
            counter2=counter2+1;

            if (counter2>n-1)
            {
                wrong=1;
                break;}
            }
            return wrong;
        }

    void print()
    {
        int dimensionn=v[1].dimension();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<dimensionn;j++)
            {
                cout<<v[i].component(j)<<"       ";
            }
            cout<<v[i].component(dimensionn)<<endl;
        }
        cout<<"finish"<<endl;
    }
    void becomeone()
    {
        int * const pivot = new int [100];
        int count1=1,nonzero=1,allzero=0,countpivot=1;
        int dimen=v[1].dimension();
        double num;
        for(int j=0;j<n;j++)
        {
            while(v[j].component(nonzero)==0)
            {
                if(nonzero>=dimen)
                {
                    allzero=1;
                    break;
                }
                nonzero++;
            }
            if(allzero==0)
            {
                num=v[j].component(nonzero);
                v[j]=v[j]/num;
                pivot[countpivot]=nonzero;
                count1=1;
                nonzero=1;
                countpivot++;
                print();
            }
        }
        print();
        lastmove(pivot);
    }

    void lastmove(int *pivott)
    {
        double firstnum1;
        double twonum1;
        double num;
        for(int i=n;i>=2;i--)
        {
            for(int j=i-1;j>=1;j--)
            {
                firstnum1=v[j-1].component(pivott[i]);
                twonum1=v[i-1].component(pivott[i]);
                num=firstnum1/twonum1;
                v[j-1]=v[j-1]-v[i-1]*num;
                print();
            }
        }
        print();
    }
    void independent()
    {
        int dimen=v[1].dimension();
        int independent=1;
        int test1=0;//test algrebra
        int c=0;//test algrebra
        int countrownumzero=0;//thr number of row is all zero
        cout<<"d"<<endl;
        cout<<dimen<<endl;
        cout<<n<<endl;

        for(int i=1;i<=dimen;i++)
        {
            for(int j=0;j<n;j++)
            {
                c=c+v[j].component(i)*v[j].component(i);
                //cout<<i<<" "<<j<<" "<<v[j].component(i)<<endl;
            }
            test1=test1+c;
        }
        if(test1==0)
            independent=0;
        if(n<dimen)
            independent=0;
        c=0;
        for(int j=0;j<n;j++)//to determinate if the number of all row is zero
        {
            for(int i=1;i<=dimen;i++)
            {
                c=c+v[j].component(i)*v[j].component(i);
                //cout<<i<<" "<<j<<" "<<v[j].component(i)<<endl;
            }
            //cout<<"c"<<" "<<c<<endl;
            if(c==0)
            {
                countrownumzero++;
                independent=0;
            }
            c=0;
        }

        if(independent==0)
            cout<<"hahaha dependent"<<endl;
        else
            cout<<"congratulations! independent"<<endl;
    }
    template<class T>
    void numcolumn(T start,T over)
    {
        int counter=0;
        while(start!=over)
        {
            counter++;
            cout<<"pivot="<<*start<<"  ,  ";
            basis(*start+1);
            start++;
        }
        cout<<"pivotnum="<<counter<<endl;
    }
    void basis(int num)
    {
        cout<<"basis is :[";
        for(int j=0;j<n;j++)
        cout<<v[j].component(num)<<",";
        cout<<"]";
        cout<<endl;
    }
    list<int> pivotnumpoint ()
    {
        int dimen=v[1].dimension();
        list<int> pointtonext;

        for(int j=0;j<n;j++)//start from zero(from up to down)
        {
            for(int i=1;i<=dimen;i++)//start from one(from left to right)
                if(v[j].component(i)>0)
                {
                    pointtonext.push_back(i-1);
                    cout<<"i=  "<<i<<",  j=  "<<j<<",  value="<<v[j].component(i)<<endl;
                    break;
                }
        }
        for (list<int>::iterator it=pointtonext.begin(); it!=pointtonext.end() ; ++it)
            cout << ' ' << *it<<"import";

        cout<<endl;
        cout<<pointtonext.size()<<"size"<<endl;
        numcolumn(pointtonext.begin(),pointtonext.end());
        return pointtonext;
    }
private:
    int n;
    Vector * v;
};



#endif // MATRIX_H_INCLUDED
